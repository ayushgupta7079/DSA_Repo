1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        
5        int n = grid.size();
6        if(n==1){
7            if(grid[0][0]==0) return 1;
8            else return -1;
9        }
10
11        if(grid[0][0] == 1) return -1;
12
13        queue<tuple<int,int,int >> q;
14        q.push({1,0,0});
15
16        int dx[8] = {1,1,1,-1,-1,-1,0,0};
17        int dy[8] = {1,0,-1,0, 1, -1, 1, -1};
18        // vector<vector<bool>> vis(n, vector<int>(n, 0));
19        // vis[0][0]=1;
20
21        while(!q.empty()){
22            auto [d, x, y] = q.front(); 
23            q.pop();
24
25            if(x == n-1 && y == n-1) return d;
26
27            for(int dir=0; dir<8;dir++){
28                int nx = x + dx[dir];
29                int ny = y + dy[dir];
30
31                if(nx <0 || ny < 0 || nx >=n || ny >= n) continue;
32                if(grid[nx][ny] == 0){
33                    grid[nx][ny]=1;
34                    q.push({d+1, nx, ny});
35                }
36            }
37        }
38        return -1;
39    }
40};