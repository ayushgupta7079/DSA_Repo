/*
841. Keys and Rooms
https://leetcode.com/problems/keys-and-rooms/description/
*/
class Solution
{
public:
  void dfs(int node, int par, vector<int> &vis, vector<vector<int>> &rooms)
  {
    vis[node] = 1;
    for (auto v : rooms[node])
    {
      if (v == par)
        continue;
      if (!vis[v])
      {
        dfs(v, node, vis, rooms);
      }
    }
  }
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {

    int n = rooms.size();
    vector<int> vis(n, 0);
    dfs(0, -1, vis, rooms);
    for (int i = 0; i < n; i++)
    {
      if (vis[i] == 0)
        return false;
    }
    return true;
  }
};