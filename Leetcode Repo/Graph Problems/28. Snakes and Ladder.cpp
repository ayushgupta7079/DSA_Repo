/*
909. Snakes and Ladders
https://leetcode.com/problems/snakes-and-ladders/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution
{
public:
  int snakesAndLadders(vector<vector<int>> &board)
  {

    int n = board.size();
    vector<int> g(n * n + 1);
    int ind = 1;
    bool dir = 1;
    for (int i = n - 1; i >= 0; i--)
    {

      if (dir)
      { // right
        for (int j = 0; j < n; j++)
        {
          g[ind++] = board[i][j];
        }
      }
      else
      { // left
        for (int j = n - 1; j >= 0; j--)
        {
          g[ind++] = board[i][j];
        }
      }

      dir ^= 1; // changing direction alternatively
    }

    vector<int> dist(n * n + 1, 1e9);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (int i = 1; i <= 6; i++)
      {
        int neigh = node + i;
        if (neigh > n * n)
          break;
        if (g[neigh] == -1)
        {
          if (dist[neigh] > dist[node] + 1)
          {
            dist[neigh] = dist[node] + 1;
            q.push(neigh);
          }
        }
        else
        {
          if (dist[g[neigh]] > dist[node] + 1)
          {
            dist[g[neigh]] = dist[node] + 1;
            q.push(g[neigh]);
          }
        }
      }
    }

    if (dist[n * n] != 1e9)
      return dist[n * n];
    return -1;
  }
};