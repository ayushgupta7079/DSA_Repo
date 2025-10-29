/*
1192. Critical Connections in a Network
https://leetcode.com/problems/critical-connections-in-a-network/description/
*/

int timer = 1;
void dfs(int node, int par, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridge, vector<vector<int>> &adj)
{

  vis[node] = 1;
  tin[node] = low[node] = timer++;
  for (auto v : adj[node])
  {
    if (v == par)
      continue;
    if (!vis[v])
    {
      dfs(v, node, vis, tin, low, bridge, adj);
      low[node] = min(low[node], low[v]);
      if (tin[node] < low[v])
      {
        bridge.push_back({node, v});
      }
    }
    else
    {
      low[node] = min(low[node], low[v]);
    }
  }
}
class Solution
{
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
  {

    vector<int> tin(n), low(n), vis(n, 0);
    vector<vector<int>> adj(n);
    for (auto v : connections)
    {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }
    vector<vector<int>> bridge;
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        dfs(i, -1, vis, tin, low, bridge, adj);
      }
    }
    return bridge;
  }
};