/*
1631. Path With Minimum Effort
https://leetcode.com/problems/path-with-minimum-effort/description/
*/

using ii = pair<int, int>;
#define F first
#define S second
class Solution
{
public:
  int minimumEffortPath(vector<vector<int>> &heights)
  {

    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    priority_queue<pair<int, ii>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    while (!pq.empty())
    {
      auto [cur_d, node] = pq.top();
      int x = node.F;
      int y = node.S;
      pq.pop();
      if (dist[x][y] < -cur_d)
        continue;

      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        int wt = abs(heights[nx][ny] - heights[x][y]);

        if (dist[nx][ny] > max(dist[x][y], wt))
        {
          dist[nx][ny] = max(dist[x][y], wt);
          pq.push({-dist[nx][ny], {nx, ny}});
        }
      }
    }
    return dist[n - 1][m - 1];
  }
};