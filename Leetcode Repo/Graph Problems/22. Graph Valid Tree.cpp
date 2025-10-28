/*
Graph Valid Tree
https://neetcode.io/problems/valid-tree?list=neetcode150
https://leetcode.com/problems/graph-valid-tree/    ----- premium

For a valid tree -
1. Edge should be n-1
2. fully connected i.e component = 1
*/

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
{
  vis[node] = 1;
  for (auto v : adj[node])
  {
    if (!vis[v])
    {
      dfs(v, vis, adj);
    }
  }
}
class Solution
{
public:
  bool validTree(int n, vector<vector<int>> &edges)
  {

    vector<vector<int>> adj(n);
    int edg_cnt = edges.size();
    if (edg_cnt != n - 1)
      return false;
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
        dfs(i, vis, adj);
      }
    }
    return comp == 1;
  }
};
