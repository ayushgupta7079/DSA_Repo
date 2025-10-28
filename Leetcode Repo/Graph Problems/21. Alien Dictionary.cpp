/*
Alien Dictionary
https://neetcode.io/problems/foreign-dictionary?list=neetcode150

Key concept :
1. Compare only adjacent words — Only consecutive words define letter order
  (words[i] vs words[i+1]).

2. Invalid order check: If a longer word comes before its prefix
  (e.g., "abc" before "ab"), return "".

3. Use vector<unordered_set<int>> adj — to avoid duplicate edges that can inflate indegrees.

4. Maintain indegree only for characters that actually appear in the input words.

5. Use Kahn’s algorithm (BFS) for topological sort to determine character order.

6. If multiple nodes have indegree = 0, their order doesn’t matter unless the problem
  specifies otherwise this also includes isolated characters which are not part of any edges
  Hence, all such nodes should be pushed into the queue at the beginning before starting topological sorting.

7. If asked for all 26 letters, append the missing ones at the end (any order).

8. Cycle detection: After topological sorting, if the result size < total characters involved → there’s a cycle → return "".
*/

class Solution
{
public:
  string foreignDictionary(vector<string> &words)
  {

    vector<unordered_set<int>> adj(26);
    vector<int> indeg(26, 0), vis(26, 0);
    int n = words.size();
    for (auto v : words)
    {
      for (auto x : v)
      {
        vis[x - 'a'] = 1;
      }
    }
    for (int i = 0; i < n - 1; i++)
    {
      string u = words[i];
      string v = words[i + 1];
      int x = u.length();
      int y = v.length();
      bool found = false;
      for (int j = 0; j < min(x, y); j++)
      {
        if (u[j] != v[j])
        {
          int a = u[j] - 'a';
          int b = v[j] - 'a';
          if (adj[a].insert(b).second)
            indeg[b]++;
          found = true;
          break;
        }
      }
      if (!found && x > y)
        return "";
    }

    int count = 0;
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
      if (vis[i])
        count += 1;
      if (vis[i] && indeg[i] == 0)
      {
        q.push(i);
      }
    }
    string ans = "";
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      ans.push_back('a' + node);
      for (auto v : adj[node])
      {
        indeg[v]--;
        if (indeg[v] == 0)
        {
          q.push(v);
        }
      }
    }
    return ans.length() == count ? ans : "";
  }
};
