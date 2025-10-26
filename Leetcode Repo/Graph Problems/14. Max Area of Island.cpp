/*
695. Max Area of Island
https://leetcode.com/problems/max-area-of-island/description/
*/

int m, n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
bool check(int x, int y)
{
  return x >= 0 && y >= 0 && x < m && y < n;
}
void dfs(int x, int y, int &area, vector<vector<int>> &vis, vector<vector<int>> &grid)
{

  vis[x][y] = 1;
  area++;

  for (int k = 0; k < 4; k++)
  {
    int nx = x + dx[k];
    int ny = y + dy[k];

    if (check(nx, ny) && grid[nx][ny] == 1 && !vis[nx][ny])
    {
      dfs(nx, ny, area, vis, grid);
    }
  }
}
class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    m = grid.size();
    n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    int area = 0;
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!vis[i][j] && grid[i][j] == 1)
        {
          dfs(i, j, area, vis, grid);
          ans = max(ans, area);
          area = 0;
        }
      }
    }
    return ans;
  }
};