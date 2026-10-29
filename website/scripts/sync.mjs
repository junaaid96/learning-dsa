// Generates website/content/ from the repo's Markdown (single source of truth).
// Never edit website/content by hand: it is wiped and rebuilt on every build.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import cfg from './site.config.mjs';

const ROOT = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '../..');
const OUT = path.resolve(ROOT, 'website/content');
const GH = cfg.gh;
fs.rmSync(OUT, { recursive: true, force: true });
fs.mkdirSync(OUT, { recursive: true });

const rel = (p) => path.relative(ROOT, p).split(path.sep).join('/');
const read = (p) => fs.readFileSync(p, 'utf8');
const exists = (p) => fs.existsSync(path.join(ROOT, p));
const isDir = (p) => exists(p) && fs.statSync(path.join(ROOT, p)).isDirectory();
const ls = (d) => (isDir(d) ? fs.readdirSync(path.join(ROOT, d)).sort() : []);

// repo-relative .md path -> route
const pages = new Map();
const groups = [];
for (const g of cfg.groups) {
  const items = [];
  for (const src of g.pages(ls)) {
    const route = src.replace(/(^|\/)README\.md$/, '').replace(/\.md$/, '');
    pages.set(src, route);
    items.push({ src, route });
  }
  groups.push({ ...g, items });
}
for (const extra of cfg.extraPages ?? []) pages.set(extra, extra.replace(/(^|\/)README\.md$/, '').replace(/\.md$/, ''));

function resolveLink(fromRel, href) {
  if (/^([a-z]+:|#|\/)/i.test(href)) return href;
  const [p, hash = ''] = href.split('#');
  const h = hash ? `#${hash}` : '';
  if (!p) return href;
  const target = path.posix.normalize(path.posix.join(path.posix.dirname(fromRel), decodeURI(p))).replace(/\/$/, '');
  for (const cand of [target, `${target}/README.md`]) if (pages.has(cand)) return `/${pages.get(cand)}${h}`;
  if (target === 'README.md' || target === '.') return `/${h}`;
  const kind = isDir(target) ? 'tree' : 'blob';
  return `${GH}/${kind}/main/${encodeURI(target)}${h}`;
}

// Rewrite links and escape Vue syntax outside code.
function rewrite(md, fromRel) {
  let inFence = false;
  return md.split('\n').map((line) => {
    if (/^\s*(```|~~~)/.test(line)) { inFence = !inFence; return line; }
    if (inFence) return line;
    line = line.replace(/\]\(([^)\s]+)\)/g, (_, h) => `](${resolveLink(fromRel, h)})`);
    // escape {{ }} and stray <Tags> outside inline code
    return line.split(/(`[^`]*`)/).map((part) => (part.startsWith('`') ? part
      : part.replace(/\{\{/g, '&#123;&#123;').replace(/\}\}/g, '&#125;&#125;')
          .replace(/<(?!\/?(details|summary|br|sub|sup|kbd|img|a|b|i|p|div|span|table|tr|td|th|thead|tbody|code|pre|hr)\b)(\/?[A-Za-z])/g, '&lt;$2'))).join('');
  }).join('\n');
}

const fm = (o) => `---\n${Object.entries(o).map(([k, v]) => `${k}: ${JSON.stringify(v)}`).join('\n')}\n---\n\n`;
const firstHeading = (md) => (md.match(/^#\s+(.+)$/m) || [, ''])[1].trim();
const plain = (s) => s.replace(/[*_`]/g, '').replace(/\[([^\]]*)\]\([^)]*\)/g, '$1');
const firstPara = (md) => {
  const para = md.split('\n\n').find((b) => b.trim() && !/^(#|\||```|!\[|-|>|\d+\.)/.test(b.trim()));
  return plain((para || '').replace(/\s+/g, ' ').trim()).slice(0, 180);
};

function walk(dir, recursive) {
  const abs = path.join(ROOT, dir);
  if (!fs.existsSync(abs)) return [];
  return fs.readdirSync(abs, { withFileTypes: true }).sort((a, b) => a.name.localeCompare(b.name))
    .flatMap((e) => {
      const p = `${dir}/${e.name}`;
      if (e.isDirectory()) return recursive && !['node_modules', '.next'].includes(e.name) ? walk(p, true) : [];
      return cfg.code[path.extname(e.name)] ? [p] : [];
    });
}

function sourceSection(srcRel) {
  if (!srcRel.endsWith('README.md')) return '';
  const dir = path.posix.dirname(srcRel);
  if (dir === '.' || !cfg.embed(dir)) return '';
  const files = walk(dir, cfg.recursive?.(dir) ?? false);
  if (!files.length) return '';
  let s = `\n\n## Source code\n\nThe files for this lesson, embedded straight from the repo. Browse the folder on [GitHub](${GH}/tree/main/${encodeURI(dir)}).\n`;
  for (const f of files) {
    const name = path.posix.relative(dir, f);
    const test = /\.test\./.test(name);
    s += `\n::: details ${name} <Badge type="${test ? 'tip' : 'info'}" text="${test ? 'test' : 'source'}" />\n[View on GitHub](${GH}/blob/main/${encodeURI(f)})\n\n\`\`\`\`${cfg.code[path.extname(f)]}\n${read(path.join(ROOT, f)).replace(/\n$/, '')}\n\`\`\`\`\n:::\n`;
  }
  return s;
}

function emit(route, srcRel, body, extra = {}) {
  const file = path.join(OUT, route === '' ? 'index.md' : `${route}/index.md`);
  fs.mkdirSync(path.dirname(file), { recursive: true });
  fs.writeFileSync(file, fm({ source: srcRel, ...extra }) + body + '\n');
}

const sidebar = [];
for (const g of groups) {
  const items = [];
  for (const { src, route } of g.items) {
    const md = read(path.join(ROOT, src));
    const title = plain(firstHeading(md)) || route;
    emit(route, src, rewrite(md, src) + sourceSection(src), { title, description: firstPara(md) });
    items.push({ text: (g.label ? g.label(src, title) : title), link: `/${route}/` });
  }
  sidebar.push({ text: g.title, collapsed: g.collapsed ?? false, items });
}
for (const src of cfg.extraPages ?? []) {
  const md = read(path.join(ROOT, src));
  emit(pages.get(src), src, rewrite(md, src) + sourceSection(src), { title: plain(firstHeading(md)), description: firstPara(md) });
}

const readme = read(path.join(ROOT, 'README.md'));
const body = readme.split('\n').filter((l, i) => !(i === 0 && l.startsWith('# ')) && !/^\s*(\[!\[|!\[)/.test(l))
  .join('\n').replace(/^## Website[\s\S]*?(?=^## )/m, '');
const home = fm({ layout: 'home', source: 'README.md', title: cfg.title, description: firstPara(body) })
  .replace(/---\n\n$/, `${cfg.hero}---\n\n`);
fs.writeFileSync(path.join(OUT, 'index.md'), home + rewrite(body, 'README.md') + '\n');
fs.writeFileSync(path.resolve(ROOT, 'website/.vitepress/sidebar.generated.json'), JSON.stringify(sidebar, null, 2));
console.log(`synced ${pages.size} pages in ${groups.length} groups`);
