/*
743. Network Delay Time
https://leetcode.com/problems/network-delay-time/description/
 */

class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {

    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto v : times)
    {
      adj[v[0]].push_back({v[1], v[2]});
    }

    vector<int> t(n + 1, 1e9);

    priority_queue<pair<int, int>> pq;
    t[k] = 0;
    pq.push({0, k});

    int ans = -1e9;

    while (!pq.empty())
    {
      int node = pq.top().second;
      int d = -pq.top().first;
      pq.pop();

      if (t[node] < d)
        continue;

      for (auto v : adj[node])
      {
        int neigh = v.first;
        int time = v.second;

        if (t[neigh] > t[node] + time)
        {
          t[neigh] = t[node] + time;
          pq.push({-t[neigh], neigh});
        }
      }
    }

    for (int i = 1; i <= n; i++)
    {
      ans = max(ans, t[i]);
    }

    if (ans == 1e9)
      return -1;
    return ans;
  }
};