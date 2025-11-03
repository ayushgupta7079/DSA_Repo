/*
1976. Number of Ways to Arrive at Destination
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
*/

using ii = pair<long long, long long>;
#define F first
#define S second
class Solution
{
public:
  int countPaths(int n, vector<vector<int>> &roads)
  {
    long long mod = 1e9 + 7;
    vector<vector<ii>> adj(n);
    for (auto v : roads)
    {
      adj[v[0]].push_back({v[1], v[2]});
      adj[v[1]].push_back({v[0], v[2]});
    }

    priority_queue<ii> pq;
    pq.push({0, 0});
    vector<long long> dist(n, 1e18);
    vector<long long> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;

    while (!pq.empty())
    {
      int node = pq.top().S;
      int cur_d = -pq.top().F;
      pq.pop();
      if (dist[node] < cur_d)
        continue;

      for (auto v : adj[node])
      {
        int neigh = v.F;
        int time = v.S;

        if (dist[neigh] > dist[node] + time)
        {
          dist[neigh] = dist[node] + time;
          pq.push({-dist[neigh], neigh});
          ways[neigh] = ways[node] % mod;
        }
        else if (dist[neigh] == dist[node] + time)
        {
          ways[neigh] = (ways[neigh] + ways[node]) % mod;
        }
      }
    }
    return ways[n - 1];
  }
};