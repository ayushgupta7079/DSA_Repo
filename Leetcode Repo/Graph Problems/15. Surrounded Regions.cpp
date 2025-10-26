/*
130. Surrounded Regions
https://leetcode.com/problems/surrounded-regions/description/
*/

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int m, n;
bool check(int x, int y)
{
  return x >= 0 && y >= 0 && x < m && y < n;
}
void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &board)
{
  vis[x][y] = 1;

  for (int k = 0; k < 4; k++)
  {
    int nx = x + dx[k];
    int ny = y + dy[k];

    if (check(nx, ny) && board[nx][ny] == 'O' && !vis[nx][ny])
    {
      dfs(nx, ny, vis, board);
    }
  }
}
class Solution
{
public:
  void solve(vector<vector<char>> &board)
  {
    m = board.size();
    n = board[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int r = 0; r < m; r++)
    {
      for (int c = 0; c < n; c++)
      {
        if (board[r][c] == 'O')
        {
          if (r == 0 || r == m - 1)
          {
            if (!vis[r][c])
            {
              dfs(r, c, vis, board);
            }
          }
          else if (c == 0 || c == n - 1)
          {
            if (!vis[r][c])
            {
              dfs(r, c, vis, board);
            }
          }
        }
      }
    }
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (vis[i][j] == 1)
        {
          board[i][j] = 'O';
        }
        else
          board[i][j] = 'X';
      }
    }
  }
};