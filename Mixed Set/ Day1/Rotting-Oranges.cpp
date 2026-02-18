1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        
5        int n = grid.size();
6        int m = grid[0].size();
7
8        queue<pair<int,int>> q; // to keep track of current pos
9        // insert all rotten 
10        int fresh = 0;
11        for(int i=0;i<n;i++){
12            for(int j=0;j<m;j++){
13                if(grid[i][j]==2){
14                    q.push({i,j});
15                }
16                else if(grid[i][j] == 1) fresh++;
17            }
18        }
19        int dx[4] = {1,0,-1,0};
20        int dy[4] = {0,-1,0,1};
21        int timer = 0;
22        while(!q.empty() && fresh > 0){
23            int sz = q.size();
24            timer++;
25            while(sz--){
26                auto [x, y] = q.front();
27                q.pop();
28                for(int dir=0; dir<4; dir++){
29                    int nx = x + dx[dir];
30                    int ny = y + dy[dir];
31
32                    if((nx >= 0 && ny >= 0 && nx < n && ny < m) && grid[nx][ny] == 1){
33                        fresh--;
34                        grid[nx][ny] = 2;
35                        q.push({nx,ny});
36                    }
37                }
38            }
39        }
40
41        return fresh == 0 ? timer : -1;
42    }
43};