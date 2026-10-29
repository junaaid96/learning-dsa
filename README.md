# learning-dsa — C++ Data Structures & Algorithms

A structured, self-checking C++17 resource for learning DSA for interviews and competitive programming. Every topic folder has a **concept guide** (`README.md`) and small, heavily commented `.cpp` files. Each file states the problem, the idea, time/space complexity and a link to a real judge problem (LeetCode / Codeforces / CSES / GfG), and its `main()` verifies itself with `assert`.

## Website

Browse every guide, C++ solution and the XPSC tracker with search and dark mode at **[junaaid96.github.io/learning-dsa](https://junaaid96.github.io/learning-dsa/)**. The site is built from this repo's Markdown by [`website/`](website/) and redeploys on every push to `main`.

## Quick start

```bash
# compile & run a single file
g++ -std=c++17 -Wall -Wextra graphs/graph_bellman_ford.cpp -o /tmp/a && /tmp/a

# compile & run everything (or one folder)
./run_all.sh
./run_all.sh dynamic_programming
CXX=clang++ ./run_all.sh   # pick a compiler
```

Each program prints `<name>: all tests passed`; `run_all.sh` prints a PASS/FAIL line per file and a summary, and exits non-zero on any failure.

## Roadmap / table of contents

Study the stages in order; inside a stage the order of the table is the suggested order.

### Stage 1 – Foundations

| Topic | Files | Guide |
|---|---|---|
| Foundations (complexity, recursion, bits) | 3 | [`foundations/`](foundations/README.md) |
| Arrays & Strings basics | 4 | [`arrays_strings/`](arrays_strings/README.md) |
| Core algorithms (binary search, merge sort, backtracking intro) | 3 | [`core_algorithms/`](core_algorithms/README.md) |
| Sorting | 3 | [`sorting/`](sorting/README.md) |

### Stage 2 – Core patterns

| Topic | Files | Guide |
|---|---|---|
| Hashing (hash maps & sets) | 5 | [`hashing/`](hashing/README.md) |
| Two Pointers & Sliding Window | 7 | [`two_pointers_sliding_window/`](two_pointers_sliding_window/README.md) |
| Prefix Sums & Difference Arrays | 4 | [`prefix_sum_difference/`](prefix_sum_difference/README.md) |
| Binary Search (on index and on answer) | 5 | [`binary_search/`](binary_search/README.md) |
| Stacks & Queues | 3 | [`stack_queue/`](stack_queue/README.md) |
| Monotonic Stack & Queue | 3 | [`monotonic_stack_queue/`](monotonic_stack_queue/README.md) |
| Linked Lists | 4 | [`linked_list/`](linked_list/README.md) |

### Stage 3 – Greedy & search

| Topic | Files | Guide |
|---|---|---|
| Greedy | 4 | [`greedy/`](greedy/README.md) |
| Heaps / Priority Queues | 3 | [`heaps/`](heaps/README.md) |
| Intervals & Sweep Line | 2 | [`intervals_sweep_line/`](intervals_sweep_line/README.md) |
| Backtracking | 4 | [`backtracking/`](backtracking/README.md) |
| Bit Manipulation | 3 | [`bit_manipulation/`](bit_manipulation/README.md) |

### Stage 4 – Trees & graphs

| Topic | Files | Guide |
|---|---|---|
| Trees, BSTs & Tries | 7 | [`trees/`](trees/README.md) |
| Graphs | 12 | [`graphs/`](graphs/README.md) |
| Disjoint Set Union (Union-Find) | 2 | [`dsu/`](dsu/README.md) |

### Stage 5 – Dynamic programming

| Topic | Files | Guide |
|---|---|---|
| Dynamic Programming | 14 | [`dynamic_programming/`](dynamic_programming/README.md) |

### Stage 6 – Competitive programming extras

| Topic | Files | Guide |
|---|---|---|
| String Algorithms | 5 | [`strings/`](strings/README.md) |
| Number Theory | 3 | [`number_theory/`](number_theory/README.md) |
| Math & Combinatorics | 2 | [`math_combinatorics/`](math_combinatorics/README.md) |
| Range Queries (Fenwick, Segment Tree, Sparse Table) | 3 | [`range_queries/`](range_queries/README.md) |
| Matrices & 2D grids | 2 | [`matrix_2d/`](matrix_2d/README.md) |
| Computational Geometry basics | 1 | [`geometry/`](geometry/README.md) |

## Extra resources in this repo

- [PATTERNS_CHEATSHEET.md](PATTERNS_CHEATSHEET.md) — "if the problem says X, think Y" table plus constraint → complexity guide.
- [XPSC/](XPSC/README.md) — 16-week day-wise practice tracker (checkbox lists) with commented solutions in `XPSC/solutions/`.

## Suggested study order (weekly plan)

1. **Weeks 1–2:** foundations, arrays/strings, sorting, hashing. Solve the *Easy* lists.
2. **Weeks 3–4:** two pointers/sliding window, prefix sums, binary search (incl. on the answer).
3. **Weeks 5–6:** stacks, monotonic stack/queue, linked lists, heaps, intervals.
4. **Weeks 7–8:** greedy, backtracking, bit manipulation.
5. **Weeks 9–11:** trees, graphs, DSU.
6. **Weeks 12–14:** dynamic programming (1D → knapsack → strings → intervals → bitmask/digit/tree).
7. **Weeks 15+:** strings, number theory, combinatorics, range queries, matrices, geometry; run XPSC in parallel.

For every topic: read the guide → read and run the example files → solve Easy → Medium → Hard from the guide → write down the pattern in your own words.

## Conventions

- C++17, no `using namespace std;`, explicit `std::`.
- Header comment: problem, link, idea, time/space, compile command.
- Line-by-line comments explain *why*, not just *what*.
- `assert`-based self-tests in `main()`; all files compile cleanly with `-Wall -Wextra`.

## License

[MIT](LICENSE) © 2026 Md. Junaidul Islam
