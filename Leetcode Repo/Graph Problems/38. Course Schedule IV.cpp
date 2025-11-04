/*
1462. Course Schedule IV
https://leetcode.com/problems/course-schedule-iv/description/
*/

class Solution
{
public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
  {

    int n = numCourses;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    for (auto v : prerequisites)
    {
      int a = v[0];
      int b = v[1];
      adj[a].push_back(b);
      indeg[b]++;
    }
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
      if (!indeg[i])
      {
        q.push(i);
      }
    }
    vector<vector<bool>> table(n, vector<bool>(n, false));

    vector<int> topo;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (auto v : adj[node])
      {
        table[node][v] = true;

        for (int i = 0; i < n; i++)
        {
          if (table[i][node])
          {
            table[i][v] = true;
          }
        }

        indeg[v]--;
        if (!indeg[v])
        {
          q.push(v);
        }
      }
    }
    vector<bool> ans;
    for (auto v : queries)
    {
      int a = v[0];
      int b = v[1];
      if (table[a][b])
      {
        ans.push_back(true);
      }
      else
      {
        ans.push_back(false);
      }
    }
    return ans;
  }
};