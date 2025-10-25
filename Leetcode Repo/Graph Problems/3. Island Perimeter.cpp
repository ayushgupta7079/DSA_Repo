// 463. Island Perimeter

class Solution
{
  int m, n;
  int ans = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};

  bool check(int x, int y)
  {
    return x >= 0 && y >= 0 && x < m && y < n;
  }
  int get_peri(int x, int y, vector<vector<int>> &gird)
  {
    int peri = 0;
    // up
    int xu = x - 1, yu = y;
    if (!check(xu, yu) || gird[xu][yu] == 0)
      peri++;
    // down
    int xd = x + 1, yd = y;
    if (!check(xd, yd) || gird[xd][yd] == 0)
      peri++;
    // left
    int xl = x, yl = y - 1;
    if (!check(xl, yl) || gird[xl][yl] == 0)
      peri++;
    // right
    int xr = x, yr = y - 1;
    if (!check(xr, yr) || gird[xr][yr] == 0)
      peri++;

    return peri;
  }

  void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &vis)
  {

    vis[x][y] = 1;
    ans += get_peri(x, y, grid);

    for (int k = 0; k < 4; k++)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (check(nx, ny) && !vis[nx][ny] && grid[nx][ny] == 1)
      {
        dfs(grid, nx, ny, vis);
      }
    }
  }

public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    m = grid.size();
    n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          dfs(grid, i, j, vis);
          i = m;
          j = n;
        }
      }
    }
    return ans;
  }
};