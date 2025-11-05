/*
2097. Valid Arrangement of Pairs
https://leetcode.com/problems/valid-arrangement-of-pairs/description/
*/
class Solution
{
public:
  void dfs(int cur, unordered_map<int, int> &out, unordered_map<int, vector<int>> &adj, vector<int> &path)
  {

    while (out[cur] != 0)
    {
      int neigh = adj[cur][--out[cur]];
      dfs(neigh, out, adj, path);
    }
    path.push_back(cur);
  }
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
  {

    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> out_deg, in_deg;
    for (auto v : pairs)
    {
      adj[v[0]].push_back(v[1]);
      out_deg[v[0]]++;
      in_deg[v[1]]++;
    }

    int start = pairs[0][0];
    for (auto v : adj)
    {
      int i = v.first;
      if (out_deg[i] - in_deg[i] == 1)
      {
        start = i;
        break;
      }
    }

    vector<int> path;
    dfs(start, out_deg, adj, path);
    reverse(path.begin(), path.end());

    vector<vector<int>> arr;
    for (int i = 1; i < path.size(); i++)
    {
      int b = path[i];
      int a = path[i - 1];
      arr.push_back({a, b});
    }
    return arr;
  }
};