1class Solution {
2public:
3    int deleteGreatestValue(vector<vector<int>>& grid) {
4        
5        int ans = 0;
6
7        for(int i=0;i<grid.size();i++){
8            sort(grid[i].begin(), grid[i].end());
9        }
10        int n = grid.size();
11        int m = grid[0].size();
12        for(int i=m-1;i>=0;i--){
13            priority_queue<int> pq;
14            for(int j=0;j<n;j++){
15                pq.push(grid[j][i]);
16            }
17            ans += pq.top();
18        }
19
20        return ans;
21    }
22};