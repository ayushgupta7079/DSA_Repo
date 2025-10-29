/*
1368. Minimum Cost to Make at Least One Valid Path in a Grid
https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

0-1 BFS
*/

using ii = pair<int, int>;
#define F first
#define S second

class Solution
{
public:
  int minCost(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    deque<ii> q;
    q.push_front({0, 0});
    dist[0][0] = 0;
    int dx[4] = {0, 0, 1, -1}; // RLDU
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty())
    {
      int x = q.front().F;
      int y = q.front().S;
      q.pop_front();
      int dir = grid[x][y] - 1;
      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        int wt = 1;
        if (dir == k)
          wt = 0;

        if (dist[nx][ny] > dist[x][y] + wt)
        {
          dist[nx][ny] = dist[x][y] + wt;
          if (wt == 0)
          {
            q.push_front({nx, ny});
          }
          else
          {
            q.push_back({nx, ny});
          }
        }
      }
    }

    return dist[n - 1][m - 1];
  }
};