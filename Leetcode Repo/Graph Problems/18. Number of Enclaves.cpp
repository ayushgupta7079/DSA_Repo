/*
1020. Number of Enclaves
https://leetcode.com/problems/number-of-enclaves/description/
*/

using ii = pair<int, int>;
#define F first
#define S second
class Solution
{
public:
  int numEnclaves(vector<vector<int>> &grid)
  {

    int n = grid.size();
    int m = grid[0].size();

    queue<ii> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
        {
          if (grid[i][j] == 1)
          {
            q.push({i, j});
            vis[i][j] = 1;
          }
        }
      }
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    while (!q.empty())
    {
      int x = q.front().F;
      int y = q.front().S;
      q.pop();

      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] == 1)
        {
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1 && !vis[i][j])
          count++;
      }
    }

    return count;
  }
};