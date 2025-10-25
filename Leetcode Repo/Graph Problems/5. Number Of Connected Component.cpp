/*
Number of connected component in an undirected graph
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
*/

class Solution
{
public:
  void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
  {
    vis[node] = 1;
    for (auto v : adj[node])
    {
      if (!vis[v])
      {
        dfs(v, adj, vis);
      }
    }
  }
  int countComponents(int n, vector<vector<int>> &edges)
  {

    vector<vector<int>> adj(n);
    for (auto v : edges)
    {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }

    vector<int> vis(n, 0);
    int comp = 0;
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        comp++;
        dfs(i, adj, vis);
      }
    }
    return comp;
  }
};
