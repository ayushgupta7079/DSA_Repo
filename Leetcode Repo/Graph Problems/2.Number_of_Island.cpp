int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int m,n;
bool check(int x,int y){
    return x >= 0 && y >= 0 && x < m && y < n ;
}
void dfs(vector<vector<char>> &grid,int x,int y,vector<vector<int>> &vis){
    vis[x][y]=1;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(check(nx,ny) && grid[nx][ny]=='1' && !vis[nx][ny]){
            dfs(grid,nx,ny,vis);
        }
    }
}
class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};
