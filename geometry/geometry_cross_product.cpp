// Computational geometry basics: cross product orientation, segment intersection,
// polygon area (shoelace), convex hull (monotone chain).
//
// Links: https://cses.fi/problemset/task/2189  (Point Location Test)
//        https://cses.fi/problemset/task/2190  (Line Segment Intersection)
//        https://cses.fi/problemset/task/2191  (Polygon Area)
//        https://cses.fi/problemset/task/2195  (Convex Hull)
//        https://leetcode.com/problems/erect-the-fence/
//
// Idea:
//   cross(b - a, c - a) > 0 -> c is LEFT of a->b, < 0 right, 0 collinear.
//   Use long long, never floating point, when inputs are integers.
//   Shoelace: 2 * area = |sum x_i y_{i+1} - x_{i+1} y_i|.
//
// Time: O(1) / O(n) / O(n log n) hull    Space: O(n)
//
// Compile: g++ -std=c++17 -Wall -Wextra geometry_cross_product.cpp -o geo && ./geo

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

struct P {
    long long x, y;
    P operator-(const P& o) const { return {x - o.x, y - o.y}; }
    bool operator<(const P& o) const { return x != o.x ? x < o.x : y < o.y; }
    bool operator==(const P& o) const { return x == o.x && y == o.y; }
};
long long cross(const P& a, const P& b) { return a.x * b.y - a.y * b.x; }
long long orient(const P& a, const P& b, const P& c) { return cross(b - a, c - a); }
int sgn(long long v) { return (v > 0) - (v < 0); }

bool onSegment(const P& a, const P& b, const P& p) {      // p collinear with a, b assumed
    return std::min(a.x, b.x) <= p.x && p.x <= std::max(a.x, b.x) &&
           std::min(a.y, b.y) <= p.y && p.y <= std::max(a.y, b.y);
}

bool segmentsIntersect(const P& a, const P& b, const P& c, const P& d) {
    int o1 = sgn(orient(a, b, c)), o2 = sgn(orient(a, b, d));
    int o3 = sgn(orient(c, d, a)), o4 = sgn(orient(c, d, b));
    if (o1 != o2 && o3 != o4) return true;                 // proper crossing
    if (o1 == 0 && onSegment(a, b, c)) return true;        // touching / overlapping cases
    if (o2 == 0 && onSegment(a, b, d)) return true;
    if (o3 == 0 && onSegment(c, d, a)) return true;
    if (o4 == 0 && onSegment(c, d, b)) return true;
    return false;
}

long long doubleArea(const std::vector<P>& poly) {         // shoelace, returns 2*area
    long long s = 0;
    for (size_t i = 0; i < poly.size(); ++i) s += cross(poly[i], poly[(i + 1) % poly.size()]);
    return std::llabs(s);
}

std::vector<P> convexHull(std::vector<P> p) {              // keeps collinear boundary points
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
    if (p.size() < 3) return p;
    std::vector<P> h;
    for (int pass = 0; pass < 2; ++pass) {                 // lower hull, then upper hull
        size_t start = h.size();
        for (const P& q : p) {
            while (h.size() >= start + 2 && orient(h[h.size() - 2], h.back(), q) < 0) h.pop_back();  // right turn
            h.push_back(q);
        }
        h.pop_back();                                      // last point repeats in the next pass
        std::reverse(p.begin(), p.end());
    }
    std::sort(h.begin(), h.end());
    h.erase(std::unique(h.begin(), h.end()), h.end());
    return h;
}

int main() {
    assert(orient({1, 1}, {5, 3}, {2, 3}) > 0);            // CSES 2189: LEFT
    assert(orient({1, 1}, {5, 3}, {2, 1}) < 0);            // RIGHT
    assert(orient({1, 1}, {5, 3}, {3, 2}) == 0);           // TOUCH
    assert(segmentsIntersect({1, 1}, {5, 3}, {1, 2}, {4, 3}) == false);
    assert(segmentsIntersect({1, 1}, {5, 3}, {1, 1}, {4, 3}) == true);
    assert(segmentsIntersect({1, 1}, {5, 5}, {1, 5}, {5, 1}) == true);
    assert(doubleArea({{1, 1}, {4, 2}, {3, 5}, {1, 4}}) == 16);   // CSES 2191 sample
    auto h = convexHull({{0, 0}, {2, 0}, {1, 1}, {2, 2}, {0, 2}, {1, 0}});
    assert(h.size() == 5);                                  // (1,1) interior, (1,0) on edge kept
    std::cout << "geometry_cross_product: all tests passed\n";
    return 0;
}
