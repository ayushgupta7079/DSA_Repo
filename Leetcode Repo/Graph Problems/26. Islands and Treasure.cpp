/*
Neetcode : -
  Islands and Treasure
  https://neetcode.io/problems/islands-and-treasure?list=neetcode250

Leetcode :-
  Walls And Gates
  https://leetcode.com/problems/walls-and-gates/description/
*/

class Solution
{
public:
  void islandsAndTreasure(vector<vector<int>> &grid)
  {

    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 0)
        {
          q.push({i, j});
        }
      }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    while (!q.empty())
    {
      auto [x, y] = q.front();
      q.pop();

      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == -1)
          continue;

        if (grid[nx][ny] > grid[x][y] + 1)
        {
          grid[nx][ny] = grid[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
};
