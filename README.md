## DSA Topic Map – Explanations & C++ Practice Problems

This folder turns the **DSA — Thinking Map** from the PDF into **concrete, code-level intuition** using small, focused C++ problems.

Each topic below has:
- **Concept**: What the idea means and when to use it.
- **Why it matters**: The interview / real-world angle.
- **Example file**: A C++ file in this folder that you can compile and run.

All examples use **modern C++**, avoid `using namespace std;`, and are written to be **self-explanatory and beginner-friendly**.

---

### 1. Foundations

#### 1.1 Time & Space Complexity
- **Concept**: Measure how running time and memory grow as input size \(n\) increases, using Big-O notation.
- **Why it matters**: Lets you choose between multiple correct solutions and avoid approaches that will time out on large inputs.
- **Example**: `foundations/time_space_complexity_demo.cpp`
  - Compares \(O(n)\), \(O(n \log n)\), and \(O(n^2)\) style loops with simple counters.

#### 1.2 Recursion & Call Stack
- **Concept**: A function that calls itself with a **smaller subproblem**, plus a **base case** to stop.
- **Why it matters**: Many DSA patterns (divide & conquer, backtracking, DP) are most naturally expressed recursively.
- **Example**: `foundations/recursion_gcd_euclidean.cpp`
  - Implements GCD using the Euclidean algorithm both **recursively** and **iteratively**.

#### 1.3 Bit Manipulation
- **Concept**: Work directly on bits using `&`, `|`, `^`, `~`, `<<`, `>>`.
- **Why it matters**: Super fast, space-efficient tricks (parity, power-of-two checks, masks) show up in interviews and low-level work.
- **Example**: `foundations/bit_manipulation_power_of_two.cpp`
  - Checks if a number is a power of two using `n & (n - 1)`.

---

### 2. Arrays & Strings

#### 2.1 Sliding Window
- **Concept**: Maintain a **window** \([l, r]\) over the array/string and move it while maintaining some property.
- **Why it matters**: Converts many naive \(O(n^2)\) subarray / substring problems to \(O(n)\).
- **Example**: `arrays_strings/sliding_window_max_sum_k.cpp`
  - Finds maximum sum of any subarray of fixed size `k`.

#### 2.2 Two Pointers
- **Concept**: Use two indices that move towards each other or in the same direction based on conditions.
- **Why it matters**: Great for **sorted arrays**, palindrome checks, and many "pair" problems.
- **Example**: `arrays_strings/two_pointers_two_sum_sorted.cpp`
  - Finds two numbers in a sorted array that sum to a target.

#### 2.3 Prefix Sum
- **Concept**: Precompute cumulative sums so you can answer range sum queries in \(O(1)\).
- **Why it matters**: Frequent pattern in subarray-sum queries and constraints where you answer many queries on the same array.
- **Example**: `arrays_strings/prefix_sum_range_query.cpp`
  - Builds a prefix sum array and answers multiple range sum queries.

#### 2.4 Kadane’s Algorithm (Max Subarray)
- **Concept**: Track current best subarray ending at index `i`, reset when it becomes negative.
- **Why it matters**: Classic DP pattern and interview staple, teaches you to carry **state** across the array.
- **Example**: `arrays_strings/kadane_max_subarray.cpp`
  - Computes the maximum subarray sum in \(O(n)\).

---

### 3. Linked List

#### 3.1 Fast & Slow Pointers – Cycle Detection
- **Concept**: Use two pointers moving at different speeds over the list.
- **Why it matters**: Detects cycles in \(O(n)\) time and \(O(1)\) extra space.
- **Example**: `linked_list/linked_list_cycle_detection.cpp`
  - Builds a sample list with a cycle and detects it using Floyd’s algorithm.

#### 3.2 Linked List Reversal
- **Concept**: Iteratively reverse the `.next` pointers using three pointers `prev`, `curr`, `next`.
- **Why it matters**: Very common utility in bigger linked-list problems (reverse in groups, etc.).
- **Example**: `linked_list/linked_list_reverse.cpp`
  - Reverses a singly linked list and prints before/after.

---

### 4. Stack & Queue

#### 4.1 Valid Parentheses (Stack)
- **Concept**: Use stack to match opening and closing brackets.
- **Why it matters**: Foundation for many parsing, compiler, and expression problems.
- **Example**: `stack_queue/stack_valid_parentheses.cpp`
  - Checks if a string of brackets is valid.

#### 4.2 Monotonic Deque – Sliding Window Maximum
- **Concept**: Maintain a deque of indices where values are **monotonically decreasing**.
- **Why it matters**: Solves sliding window maximum in \(O(n)\) instead of \(O(nk)\).
- **Example**: `stack_queue/deque_sliding_window_maximum.cpp`
  - Computes max for each window of size `k`.

---

### 5. Trees

#### 5.1 Binary Tree Traversals
- **Concept**: Visit nodes in different orders (preorder, inorder, postorder, level order).
- **Why it matters**: Basis for almost all tree problems.
- **Example**: `trees/tree_traversals_basic.cpp`
  - Builds a small binary tree and prints traversals.

#### 5.2 Binary Search Tree (BST) Operations
- **Concept**: Ordered binary tree with left < root < right.
- **Why it matters**: Enables logarithmic-time search, insert, and delete in average case.
- **Example**: `trees/bst_insert_search_inorder.cpp`
  - Inserts nodes, searches values, and prints inorder traversal.

#### 5.3 Lowest Common Ancestor (LCA)
- **Concept**: Find the deepest node that is an ancestor of two given nodes.
- **Why it matters**: Appears in tree / graph problems related to hierarchy and paths.
- **Example**: `trees/tree_lca_binary_tree.cpp`
  - Finds LCA in a general binary tree using recursion.

---

### 6. Graphs

#### 6.1 BFS – Shortest Path in Unweighted Graph
- **Concept**: Level-by-level traversal using a queue.
- **Why it matters**: Gives shortest path (in edges) in unweighted graphs.
- **Example**: `graphs/graph_bfs_shortest_path.cpp`
  - Finds shortest path between two vertices in an unweighted graph.

#### 6.2 DFS – Connected Components
- **Concept**: Depth-first traversal using recursion or an explicit stack.
- **Why it matters**: Used to find connected components, detect cycles, and explore all reachable nodes.
- **Example**: `graphs/graph_dfs_connected_components.cpp`
  - Counts connected components in an undirected graph.

#### 6.3 Topological Sort (Kahn’s Algorithm)
- **Concept**: Linear ordering of vertices where each directed edge `u → v` means `u` comes before `v`.
- **Why it matters**: Core for scheduling, build systems, and dependency resolution in DAGs.
- **Example**: `graphs/graph_toposort_kahn.cpp`
  - Performs topological sort on a DAG using BFS-style in-degree approach.

#### 6.4 Dijkstra – Shortest Path with Weights
- **Concept**: Greedy algorithm using a priority queue for non-negative edge weights.
- **Why it matters**: Standard for routing and pathfinding where edges have different costs.
- **Example**: `graphs/graph_dijkstra_shortest_path.cpp`
  - Computes shortest paths from a source node in a weighted graph.

---

### 7. Core Algorithms & Patterns

#### 7.1 Binary Search
- **Concept**: Repeatedly halve the search space in a sorted array.
- **Why it matters**: Extremely common pattern; also used inside many other algorithms.
- **Example**: `core_algorithms/binary_search_variants.cpp`
  - Shows standard binary search, first occurrence, and last occurrence.

#### 7.2 Merge Sort (Divide & Conquer)
- **Concept**: Divide array, sort halves recursively, then merge.
- **Why it matters**: Stable \(O(n \log n)\) sort; great example of divide & conquer.
- **Example**: `core_algorithms/merge_sort_demo.cpp`
  - Implements merge sort and prints sorted output.

#### 7.3 Backtracking – Subsets
- **Concept**: Systematically build solutions, undo choices when they no longer work.
- **Why it matters**: Core pattern for permutations, combinations, N-Queens, Sudoku, etc.
- **Example**: `core_algorithms/backtracking_subsets.cpp`
  - Generates all subsets of a set of integers.

---

### 8. Dynamic Programming (DP)

#### 8.1 0/1 Knapsack
- **Concept**: Decide for each item whether to take it or leave it, with a weight constraint.
- **Why it matters**: Teaches how to define a DP state and transition; many problems reduce to knapsack-like states.
- **Example**: `dynamic_programming/dp_knapsack_01.cpp`
  - Classic DP table solution for 0/1 knapsack.

#### 8.2 Longest Increasing Subsequence (LIS)
- **Concept**: Longest subsequence where elements strictly increase.
- **Why it matters**: Trains you to think about **subsequence vs subarray** and DP state over indices.
- **Example**: `dynamic_programming/dp_lis_n2.cpp`
  - \(O(n^2)\) DP implementation for LIS with reconstruction of one LIS.

#### 8.3 Matrix DP – Unique Paths
- **Concept**: Grid-based DP where `dp[i][j]` depends on neighbors (top/left).
- **Why it matters**: Many path / grid problems share this pattern.
- **Example**: `dynamic_programming/dp_unique_paths_grid.cpp`
  - Counts number of ways to go from top-left to bottom-right moving only right or down.

---

### How to Use This Folder

- **Read the PDF DSA section**, then:
  1. Pick a topic you want to strengthen.
  2. Open the corresponding `.cpp` file listed above.
  3. Read the comments at the top to understand the problem and approach.
  4. Compile and run, tweak inputs, and try to:
     - Change constraints.
     - Add edge cases.
     - Re-implement from scratch without looking.

- Over time, you should be able to:
  - **Recognize patterns** from the problem description (sliding window, two pointers, DP, etc.).
  - **Explain trade-offs**: time vs space, brute-force vs optimized.
  - **Code cleanly** under time pressure with clear structure and variable names.

Add more `.cpp` files as you practice new problems, following the same structure and style.

