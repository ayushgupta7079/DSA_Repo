/*
785. Is Graph Bipartite?
https://leetcode.com/problems/is-graph-bipartite/description/
*/
bool dfs(int node, int col, vector<int> &vis, vector<vector<int>> &graph)
{
  vis[node] = col;
  for (auto v : graph[node])
  {
    if (!vis[v])
    {
      if (dfs(v, 3 - col, vis, graph))
      {
        return true;
      }
    }
    else if (vis[v] == vis[node])
    {
      return true;
    }
  }
  return false;
}
class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        if (dfs(i, 1, vis, graph))
        {
          return false;
        }
      }
    }
    return true;
  }
};