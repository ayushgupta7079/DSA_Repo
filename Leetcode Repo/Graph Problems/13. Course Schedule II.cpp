/*
210. Course Schedule II
https://leetcode.com/problems/course-schedule-ii/description/
*/
class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    int n = numCourses;
    vector<int> indeg(n, 0);
    vector<vector<int>> adj(n);
    for (auto v : prerequisites)
    {
      int a = v[1];
      int b = v[0];
      indeg[b]++;
      adj[a].push_back(b);
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (indeg[i] == 0)
      {
        q.push(i);
      }
    }
    vector<int> topo;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      topo.push_back(node);
      for (auto v : adj[node])
      {

        indeg[v]--;
        if (indeg[v] == 0)
        {
          q.push(v);
        }
      }
    }

    if (topo.size() == n)
      return topo;
    return {};
  }
};