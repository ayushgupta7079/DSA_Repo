/*
787. Cheapest Flights Within K Stops
https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
Time - 20 min
*/

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    // {dist,{node,stops}}

    vector<vector<pair<int, int>>> adj(n);
    for (auto v : flights)
    {
      adj[v[0]].push_back({v[1], v[2]});
    }

    vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
    priority_queue<pair<int, pair<int, int>>> pq;
    dist[src][0] = 0;
    pq.push({0, {src, 0}});

    while (!pq.empty())
    {
      auto state = pq.top();
      int cur_d = -state.first;
      int node = state.second.first;
      int stops = state.second.second;

      pq.pop();
      if (stops == k + 1)
        continue;

      for (auto v : adj[node])
      {
        int neigh = v.first;
        int d = v.second;

        if (dist[neigh][stops + 1] > dist[node][stops] + d)
        {
          dist[neigh][stops + 1] = dist[node][stops] + d;
          pq.push({-dist[neigh][stops + 1], {neigh, stops + 1}});
        }
      }
    }

    int ans = 1e9;
    for (int i = 0; i <= k + 1; i++)
    {
      ans = min(ans, dist[dst][i]);
    }
    return ans == 1e9 ? -1 : ans;
  }
};