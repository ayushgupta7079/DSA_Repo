1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int ans = 0;
5        int n = points.size();
6        for(int i=1;i<n;i++){
7            int x = points[i][0];
8            int y = points[i][1];
9
10            int px = points[i-1][0];
11            int py = points[i-1][1];
12
13            int stepx = abs(x - px);
14            int stepy = abs(y - py);
15
16            int step = min(stepx,stepy);
17            ans += step;
18            ans += (stepx - step) + (stepy - step);
19        }
20        return ans;
21    }
22};