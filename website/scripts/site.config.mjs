const stages = [
  ['Stage 1 · Foundations', ['foundations', 'arrays_strings', 'core_algorithms', 'sorting']],
  ['Stage 2 · Core patterns', ['hashing', 'two_pointers_sliding_window', 'prefix_sum_difference', 'binary_search', 'stack_queue', 'monotonic_stack_queue', 'linked_list']],
  ['Stage 3 · Greedy & search', ['greedy', 'heaps', 'intervals_sweep_line', 'backtracking', 'bit_manipulation']],
  ['Stage 4 · Trees & graphs', ['trees', 'graphs', 'dsu']],
  ['Stage 5 · Dynamic programming', ['dynamic_programming']],
  ['Stage 6 · Competitive programming extras', ['strings', 'number_theory', 'math_combinatorics', 'range_queries', 'matrix_2d', 'geometry']],
];
export default {
  repo: 'learning-dsa',
  short: 'C++ DSA',
  gh: 'https://github.com/junaaid96/learning-dsa',
  title: 'C++ Data Structures & Algorithms',
  description: 'A structured, self-checking C++17 resource for learning data structures and algorithms for interviews and competitive programming.',
  code: { '.cpp': 'cpp', '.h': 'cpp', '.hpp': 'cpp' },
  embed: (dir) => !dir.startsWith('XPSC'),
  groups: [
    ...stages.map(([title, dirs]) => ({ title, pages: () => dirs.map((d) => `${d}/README.md`) })),
    { title: 'Cheatsheet', pages: () => ['PATTERNS_CHEATSHEET.md'] },
    { title: 'XPSC 16-week tracker', collapsed: true,
      pages: (ls) => ['XPSC/README.md', ...ls('XPSC').filter((f) => /^Week-\d+\.md$/.test(f)).map((f) => `XPSC/${f}`)] },
  ],
  nav: [
    { text: 'Roadmap', link: '/' },
    { text: 'Topics', link: '/foundations/' },
    { text: 'Cheatsheet', link: '/PATTERNS_CHEATSHEET/' },
    { text: 'XPSC', link: '/XPSC/' },
  ],
  hero: `hero:
  name: "learning-dsa"
  text: "Data structures & algorithms in C++17"
  tagline: "28 topic guides with self-checking C++ solutions linked to LeetCode, Codeforces, CSES and GfG problems, plus a 16-week XPSC practice tracker."
  actions:
    - theme: brand
      text: Start with foundations
      link: /foundations/
    - theme: alt
      text: Patterns cheatsheet
      link: /PATTERNS_CHEATSHEET/
    - theme: alt
      text: XPSC tracker
      link: /XPSC/
features:
  - title: Concept guides
    details: What it is, when to use it, intuition, patterns and a template for every topic.
    link: /foundations/
  - title: Self-checking C++
    details: Every solution is embedded with its asserts; run ./run_all.sh to verify them all.
    link: /graphs/
  - title: XPSC practice
    details: 16 weeks and nearly 500 problems, with 42 commented solutions.
    link: /XPSC/
`,
};
