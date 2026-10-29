# Docs website

VitePress site published to https://junaaid96.github.io/learning-dsa/ by `.github/workflows/pages.yml`.

`scripts/sync.mjs` turns the repo's Markdown and `.cpp` files into `content/` (git-ignored) on every build, so edit the repo files, not `content/`. Groups and the home page live in `scripts/site.config.mjs`.

```bash
cd website
npm ci
npm run dev     # local preview
npm run build   # output in .vitepress/dist
```
