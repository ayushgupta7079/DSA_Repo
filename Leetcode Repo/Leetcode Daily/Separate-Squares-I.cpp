1class Solution {
2public:
3    bool check(long double mid, const vector<vector<int>>& sq, long double area) {
4        long double curArea = 0.0;
5
6        for (const auto& v : sq) {
7            long double y = v[1];
8            long double l = v[2];
9            long double ny = y + l;
10
11            if (y >= mid) continue;
12            else if (ny <= mid) {
13                curArea += l * l;
14            } else {
15                curArea += (mid - y) * l;
16            }
17        }
18        return curArea >= area;
19    }
20
21    double separateSquares(vector<vector<int>>& squares) {
22        long double lo = 1e18, hi = -1e18;
23        long double area = 0.0;
24
25        for (const auto& v : squares) {
26            long double y = v[1];
27            long double l = v[2];
28            lo = min(lo, y);
29            hi = max(hi, y + l);
30            area += l * l;
31        }
32
33        area /= 2.0;
34
35        long double ans = lo;
36        for (int i = 0; i < 46; i++) {
37            long double mid = (lo + hi) / 2;
38            if (check(mid, squares, area)) {
39                ans = mid;
40                hi = mid;
41            } else {
42                lo = mid;
43            }
44        }
45        return ans;
46    }
47};
48