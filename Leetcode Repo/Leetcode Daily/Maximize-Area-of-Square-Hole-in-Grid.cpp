1class Solution {
2public:
3    int maxGap(vector<int>& bars) {
4    if (bars.empty()) return 1;
5
6    int cur = 1, best = 1;
7    for (int i = 1; i < bars.size(); i++) {
8        if (bars[i] == bars[i - 1] + 1) {
9            cur++;
10        } else {
11            cur = 1;
12        }
13        best = max(best, cur);
14    }
15    return best + 1;
16}
17
18    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
19        
20        sort(hBars.begin(), hBars.end());
21        sort(vBars.begin(), vBars.end());
22        int h = maxGap(hBars);
23        int v = maxGap(vBars);
24
25        int side = min(h, v);
26        return side * side;
27    }
28};