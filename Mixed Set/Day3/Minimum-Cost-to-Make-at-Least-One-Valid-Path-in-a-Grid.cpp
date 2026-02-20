1class Solution {
2public:
3    #define F first
4    #define S second
5    int minCost(vector<vector<int>>& grid) {
6        
7        int n = grid.size();
8        int m = grid[0].size();
9
10        deque<pair<int,int>> q;
11        q.push_back({0,0});
12
13        vector<vector<int>> dist(n, vector<int>(m, 1e9));
14        dist[0][0]=0;
15
16        int dx[4] = {0,0,1,-1}; // R, L, D, U
17        int dy[4] = {1,-1,0,0};
18
19        while(!q.empty()){
20            auto state = q.front();
21            q.pop_front();
22            int x = state.F;
23            int y = state.S;
24
25            int cur_dir = grid[x][y];
26            for(int dir=0; dir<4; dir++){
27                int c = 1;
28                if(dir == cur_dir-1){
29                    c = 0;
30                }
31
32                int nx = x + dx[dir];
33                int ny = y + dy[dir];
34
35                if((nx >= 0 && ny >=0 && nx < n && ny < m) && dist[nx][ny] > dist[x][y] + c){
36                    dist[nx][ny] = dist[x][y] + c;
37
38                    if(c == 0){
39                        q.push_front({nx,ny});
40                    }
41                    else{
42                        q.push_back({nx, ny});
43                    }
44                }
45            }
46        }
47
48        return dist[n-1][m-1];
49    }
50};