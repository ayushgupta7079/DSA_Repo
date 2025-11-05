/*
332. Reconstruct Itinerary
https://leetcode.com/problems/reconstruct-itinerary/description/
*/

class Solution
{
public:
  void dfs(int node, vector<int> &out, vector<vector<int>> &adj, map<int, string> &mp2, vector<string> &euler_path)
  {
    while (out[node])
    {
      int neigh = adj[node][--out[node]];
      dfs(neigh, out, adj, mp2, euler_path);
    }

    euler_path.push_back(mp2[node]);
  }
  vector<string> findItinerary(vector<vector<string>> &tickets)
  {

    map<string, int> mp;
    map<int, string> mp2;
    int id = 1;
    set<string> st;
    for (auto v : tickets)
    {
      st.insert(v[0]);
      st.insert(v[1]);
    }
    for (auto v : st)
    {
      mp[v] = id;
      mp2[id++] = v;
    }

    vector<vector<int>> adj(id + 1);
    vector<int> out(id + 1);
    for (auto v : tickets)
    {
      int a = mp[v[0]];
      int b = mp[v[1]];
      adj[a].push_back(b);
      out[a]++;
    }
    for (int i = 1; i <= id; i++)
    {
      sort(adj[i].rbegin(), adj[i].rend());
    }

    int start = mp["JFK"];
    vector<string> euler_path;
    dfs(start, out, adj, mp2, euler_path);
    reverse(euler_path.begin(), euler_path.end());
    return euler_path;
  }
};