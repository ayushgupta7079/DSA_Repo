1class Solution {
2public:
3    int n,m;
4    int dx[4] = {1,0,-1,0};
5    int dy[4] = {0,-1,0,1};
6    void dfs(int x, int y,vector<vector<char>>& board, vector<vector<int>>& vis){
7        vis[x][y]=1;
8
9        for(int k =0; k<4; k++){
10            int nx = x + dx[k];
11            int ny = y + dy[k];
12
13            if(nx >= 0 && nx < n && ny >=0 && ny < m && board[nx][ny] == 'X' && !vis[nx][ny]){
14                dfs(nx, ny, board, vis);
15            }
16        }
17    }
18
19    int countBattleships(vector<vector<char>>& board) {
20        n = board.size();
21        m = board[0].size();
22        int comp =0;
23        vector<vector<int>> vis(n, vector<int>(m,0));
24        for(int i=0;i<n;i++){
25            for(int j=0;j<m;j++){
26                if(!vis[i][j] && board[i][j]=='X'){
27                    comp++;
28                    dfs(i,j,board,vis);
29                }
30            }
31        }
32
33        return comp;
34    }
35};