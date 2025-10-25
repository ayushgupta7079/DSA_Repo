/*
994. Rotting Oranges
https://leetcode.com/problems/rotting-oranges/description/
*/

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({i, j});
          dist[i][j] = 0;
        }
      }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    while (!q.empty())
    {
      pair<int, int> node = q.front();
      q.pop();

      for (int k = 0; k < 4; k++)
      {
        int x = node.first + dx[k];
        int y = node.second + dy[k];

        if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] != 0 &&
            dist[x][y] > dist[node.first][node.second] + 1)
        {
          dist[x][y] = dist[node.first][node.second] + 1;
          q.push({x, y});
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          if (dist[i][j] == 1e9)
            return -1;
          else
          {
            ans = max(ans, dist[i][j]);
          }
        }
      }
    }
    return ans;
  }
};