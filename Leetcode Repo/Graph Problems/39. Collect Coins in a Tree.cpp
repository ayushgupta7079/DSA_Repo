/*
2603. Collect Coins in a Tree
https://leetcode.com/problems/collect-coins-in-a-tree/description/
*/

class Solution
{

public:
  int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges)
  {

    int n = coins.size();
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    for (auto v : edges)
    {
      int a = v[0];
      int b = v[1];
      adj[a].push_back(b);
      adj[b].push_back(a);
      deg[a]++;
      deg[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (deg[i] == 1 && !coins[i])
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      if (deg[node] == 0)
        continue;
      deg[node] = 0;

      for (auto v : adj[node])
      {
        if (deg[v] > 0)
        {
          deg[v]--;
          if (deg[v] == 1 && !coins[v])
            q.push(v);
        }
      }
    }
    for (int k = 1; k <= 2; k++)
    {
      for (int i = 0; i < n; i++)
      {
        if (deg[i] == 1)
        {
          q.push(i);
        }
      }
      while (!q.empty())
      {
        int node = q.front();
        q.pop();
        if (deg[node] == 0)
          continue;
        deg[node] = 0;

        for (auto v : adj[node])
        {
          if (deg[v] > 0)
            deg[v]--;
        }
      }
    }
    int count = 0;
    for (auto v : edges)
    {
      if (deg[v[0]] > 0 && deg[v[1]] > 0)
        count++;
    }
    return (count) * 2;
  }
};