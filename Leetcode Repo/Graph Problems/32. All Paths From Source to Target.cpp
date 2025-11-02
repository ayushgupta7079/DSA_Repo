/*
797. All Paths From Source to Target
https://leetcode.com/problems/all-paths-from-source-to-target/description/
*/

int n;
vector<vector<int>> ans;
void dfs(int node, vector<int> &arr, vector<vector<int>> &g)
{

  // base case
  if (node == n - 1)
  {
    ans.push_back(arr);
    return;
  }
  // transition
  for (auto v : g[node])
  {
    arr.push_back(v);
    dfs(v, arr, g);
    arr.pop_back();
  }
}
class Solution
{
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {

    n = graph.size();
    ans.clear();

    vector<int> arr;
    arr.push_back(0);
    dfs(0, arr, graph);

    return ans;
  }
};