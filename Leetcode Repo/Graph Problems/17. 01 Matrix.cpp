/*
542. 01 Matrix
https://leetcode.com/problems/01-matrix/description/
*/
using ii = pair<int, int>;
#define F first
#define S second

class Solution
{
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    queue<ii> q;

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mat[i][j] == 0)
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
      int x = q.front().F;
      int y = q.front().S;
      q.pop();

      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] > dist[x][y] + 1)
        {
          dist[nx][ny] = dist[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }
    return dist;
  }
};