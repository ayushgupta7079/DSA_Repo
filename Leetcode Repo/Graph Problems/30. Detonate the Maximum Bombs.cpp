/*
2101. Detonate the Maximum Bombs
https://leetcode.com/problems/detonate-the-maximum-bombs/description/
*/

long long get_dist(int x, int y, int nx, int ny)
{
  return (1ll * (x - nx) * (x - nx) + 1ll * (y - ny) * (y - ny));
}
void dfs(int node, int &size, vector<int> &vis, vector<vector<int>> &adj)
{
  vis[node] = 1;
  size++;
  for (auto v : adj[node])
  {
    if (!vis[v])
    {
      dfs(v, size, vis, adj);
    }
  }
}
class Solution
{
public:
  int maximumDetonation(vector<vector<int>> &bombs)
  {

    int n = bombs.size();
    vector<vector<int>> adj(n);
    vector<int> size(n);

    for (int i = 0; i < n; i++)
    {
      int x = bombs[i][0];
      int y = bombs[i][1];
      int ri = bombs[i][2];
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        int nx = bombs[j][0];
        int ny = bombs[j][1];

        long long dist = get_dist(x, y, nx, ny);
        if (1ll * ri * ri >= dist)
        {
          adj[i].push_back(j);
        }
      }
    }

    vector<vector<int>> vis(n, vector<int>(n, 0));
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      int size = 0;
      dfs(i, size, vis[i], adj);
      ans = max(ans, size);
    }
    return ans;
  }
};