/*
127. Word Ladder
https://leetcode.com/problems/word-ladder/description/
*/
bool is_valid(string a, string b)
{
  if (a.length() != b.length())
    return 0;

  int count = 0;
  for (int i = 0; i < a.length(); i++)
  {
    if (a[i] != b[i])
      count++;
  }
  return count == 1 ? 1 : 0;
}
class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {

    unordered_map<string, int> mp;
    int id = 1;
    mp[beginWord] = id++;

    for (auto v : wordList)
    {
      mp[v] = id++;
    }
    mp[endWord] = id++;
    vector<vector<int>> adj(id + 1);
    wordList.push_back(beginWord);

    for (int i = 0; i < wordList.size(); i++)
    {
      for (int j = i + 1; j < wordList.size(); j++)
      {
        string u = wordList[i];
        string v = wordList[j];
        if (is_valid(u, v))
        {
          adj[mp[u]].push_back(mp[v]);
          adj[mp[v]].push_back(mp[u]);
        }
      }
    }

    queue<int> q;
    vector<int> dist(id + 1, 1e9);
    q.push(mp[beginWord]);
    dist[mp[beginWord]] = 1;

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      for (auto v : adj[node])
      {
        if (dist[v] > dist[node] + 1)
        {
          dist[v] = dist[node] + 1;
          q.push(v);
        }
      }
    }

    return dist[mp[endWord]] == 1e9 ? 0 : dist[mp[endWord]];
  }
};