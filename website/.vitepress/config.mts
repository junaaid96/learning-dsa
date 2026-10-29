import { defineConfig } from 'vitepress';
import { withMermaid } from 'vitepress-plugin-mermaid';
import sidebar from './sidebar.generated.json' with { type: 'json' };
import cfg from '../scripts/site.config.mjs';

const SITE = `https://junaaid96.github.io/${cfg.repo}/`;

export default withMermaid(defineConfig({
  srcDir: 'content',
  base: `/${cfg.repo}/`,
  lang: 'en-US',
  title: cfg.repo,
  titleTemplate: `:title · ${cfg.short}`,
  description: cfg.description,
  cleanUrls: true,
  lastUpdated: true,
  ignoreDeadLinks: true,
  sitemap: { hostname: SITE },
  head: [
    ['meta', { name: 'theme-color', content: '#3c8772' }],
    ['meta', { property: 'og:type', content: 'website' }],
    ['meta', { property: 'og:site_name', content: cfg.repo }],
    ['meta', { name: 'twitter:card', content: 'summary' }],
  ],
  transformPageData(page) {
    const route = page.relativePath.replace(/(^|\/)index\.md$/, '$1').replace(/\.md$/, '');
    const title = page.frontmatter.title || page.title || cfg.repo;
    const desc = page.frontmatter.description || page.description || cfg.description;
    page.frontmatter.head ??= [];
    page.frontmatter.head.push(
      ['link', { rel: 'canonical', href: SITE + route }],
      ['meta', { property: 'og:title', content: title }],
      ['meta', { property: 'og:url', content: SITE + route }],
      ['meta', { property: 'og:description', content: desc }],
    );
  },
  markdown: { lineNumbers: true },
  themeConfig: {
    nav: cfg.nav,
    sidebar,
    socialLinks: [{ icon: 'github', link: cfg.gh }],
    search: { provider: 'local' },
    outline: { level: [2, 3] },
    editLink: {
      // literal URL baked in: VitePress serialises this function to the client
      pattern: new Function("{ frontmatter }", `return "${cfg.gh}/blob/main/" + (frontmatter.source ?? "")`) as any,
      text: 'View source on GitHub',
    },
    footer: { message: 'Released under the MIT License.', copyright: '© 2026 Md. Junaidul Islam' },
  },
  mermaid: { theme: 'default' },
}));
