class Solution
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
  {

    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      double p = succProb[i];

      adj[u].push_back({v, p});
      adj[v].push_back({u, p});
    }
    vector<double> dist(n, 0.0);
    priority_queue<pair<double, int>> pq;
    dist[start_node] = 1.0;
    pq.push({1.0, start_node});

    while (!pq.empty())
    {
      int node = pq.top().second;
      double curr_p = pq.top().first;
      pq.pop();

      // cout<<node<<" " << curr_p<<endl;

      if (dist[node] > curr_p)
        continue;

      for (auto v : adj[node])
      {
        int neigh = v.first;
        double prob = v.second;

        if (dist[neigh] < dist[node] * prob)
        {
          dist[neigh] = dist[node] * prob;
          pq.push({dist[neigh], neigh});
        }
      }
    }

    return dist[end_node];
  }
};
