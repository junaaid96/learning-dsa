# Computational Geometry basics

[← back to roadmap](../README.md)

## What it is

Orientation via the cross product: left/right turns, segment intersection, polygon area.

## When to use it

- Is a point left/right of a line
- Do segments intersect
- Area of a polygon (shoelace)

## Intuition

cross(b−a, c−a) > 0 means a→b→c turns left; = 0 collinear. Use integers to avoid precision issues.

## Common patterns

- Orientation test
- Shoelace formula
- Convex hull (monotone chain)

## Template

```cpp
long long cross(P a, P b, P c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }
```

## Pitfalls

- Floating point — prefer long long
- Collinear edge cases in intersection

## Complexity

O(1) per test; hull O(n log n).

## Files in this folder

| File | What it shows | Problem link |
|---|---|---|
| [`geometry_cross_product.cpp`](geometry_cross_product.cpp) | Computational geometry basics: cross product orientation, segment intersection, | [link](https://cses.fi/problemset/task/2189) |

Compile any file: `g++ -std=c++17 -Wall -Wextra file.cpp && ./a.out` (or `./run_all.sh geometry` from the repo root).

## Practice problems (easy → hard)

**Easy**

- [ ] [CSES 2189 – Point Location Test](https://cses.fi/problemset/task/2189)

**Medium**

- [ ] [CSES 2190 – Line Segment Intersection](https://cses.fi/problemset/task/2190)
- [ ] [CSES 2191 – Polygon Area](https://cses.fi/problemset/task/2191)

**Hard**

- [ ] [CSES 2195 – Convex Hull](https://cses.fi/problemset/task/2195)
- [ ] [Erect The Fence](https://leetcode.com/problems/erect-the-fence/)
