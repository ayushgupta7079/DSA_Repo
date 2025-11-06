/*
685. Redundant Connection II
https://leetcode.com/problems/redundant-connection-ii/description/
*/

class Solution
{
public:
  int nn = -1;
  map<int, int> mp;
  void dfs(int node, int par, vector<int> &pp, vector<int> &vis, vector<vector<int>> &adj)
  {

    vis[node] = 2;
    pp[node] = par;
    for (auto v : adj[node])
    {
      if (vis[v] == 1)
      {
        dfs(v, node, pp, vis, adj);
      }
      else if (vis[v] == 2)
      {
        nn = node;
        pp[v] = node;
        int cur = node;
        while (pp[cur] != node)
        {
          mp[pp[cur]] = cur;
          cur = pp[cur];
        }
        mp[pp[cur]] = cur;
      }
    }
    vis[node] = 3;
  }
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
  {

    int n = edges.size();
    vector<int> in_deg(n + 1, 0), out(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (auto v : edges)
    {
      in_deg[v[1]]++;
      out[v[0]]++;
      adj[v[0]].push_back(v[1]);
    }

    // DFS
    nn = -1;
    vector<int> vis(n + 1, 1), pp(n + 1);
    for (int i = 1; i <= n; i++)
    {
      if (vis[i] == 1)
      {
        dfs(i, -1, pp, vis, adj);
      }
    }
    // DFS END
    // find if node has 2 indeg
    bool is_two = false;
    int node2 = -1;

    for (int i = 1; i <= n; i++)
    {
      if (in_deg[i] == 2)
      {
        is_two = true;
        node2 = i;
      }
    }

    if (is_two)
    {
      for (int i = n - 1; i >= 0; i--)
      {
        int u = edges[i][0];
        int v = edges[i][1];
        if (v == node2)
        {
          //  cycle
          if (nn != -1)
          {
            if (mp[u] == v)
              return {u, v};
          }

          // no cycle
          else
          {
            return {u, v};
          }
        }
      }
    }
    else
    {
      // CYCLE
      for (int i = n - 1; i >= 0; i--)
      {
        int u = edges[i][0];
        int v = edges[i][1];
        if (mp[u] == v)
          return {u, v};
      }
    }
    return {-1, -1};
  }
};

/*
Implemented this logic and find out someone posted same logic. So adding this here to revise if I forgot the logic

-----------------------------------------------------------------------------------------------------------
Assume you had a directed tree. Then let's look at the number of incoming edges to a vertex. Root has 0 incoming, all remaining has 1 incoming edge. So, we have an array of incoming edges looking as following [0, 1, 1, 1, ... 1].

What happens when we add extra directed edge to a graph. Our array can become one of following types:
[0, 2, 1, 1, ... 1] and [1, 1, 1, 1, ... 1].

In first case, we got vertex with two incoming edges. It becomes clear to which vertex new edge has been added, and since it has only two incoming edges it is possible in linear time to check whether we can delete each of them.

In second case, it is possible to prove that there is a cycle, and that all edges connected to that cycle are outcoming. Thus, we can remove any edge from this cycle.
*/
