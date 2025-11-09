/*
886. Possible Bipartition
http://leetcode.com/problems/possible-bipartition/description/
*/

class Solution
{
public:
  bool poss = true;
  void dfs(int node, int col, vector<int> &vis, vector<vector<int>> &adj)
  {
    vis[node] = col;
    for (auto v : adj[node])
    {
      if (!vis[v])
      {
        dfs(v, 3 - col, vis, adj);
      }
      else if (vis[v] == vis[node])
      {
        poss = false;
      }
    }
  }

  bool possibleBipartition(int n, vector<vector<int>> &dislikes)
  {

    vector<int> vis(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (auto v : dislikes)
    {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }
    poss = 1;
    for (int i = 1; i <= n; i++)
    {
      if (!vis[i])
      {
        dfs(i, 1, vis, adj);
      }
    }
    return poss;
  }
};
