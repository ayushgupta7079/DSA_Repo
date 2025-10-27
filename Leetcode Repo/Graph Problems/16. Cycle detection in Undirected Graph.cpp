
/*
Undirected Graph Cycle
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/
bool dfs(int node, int par, vector<int> &vis, vector<vector<int>> &adj)
{
  vis[node] = 1;
  for (auto v : adj[node])
  {
    if (!vis[v])
    {
      if (dfs(v, node, vis, adj))
        return true;
    }
    else if (v != par)
    {
      return true;
    }
  }
  return false;
}

class Solution
{
public:
  bool isCycle(int V, vector<vector<int>> &edges)
  {
    // Code here
    int E = edges.size();
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        if (dfs(i, -1, vis, adj))
        {
          return true;
        }
      }
    }
    return false;
  }
};