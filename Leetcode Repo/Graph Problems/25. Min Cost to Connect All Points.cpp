/*
1584. Min Cost to Connect All Points
https://leetcode.com/problems/min-cost-to-connect-all-points/description/

Solution : Krushkal's Algorithm using Union Find
*/

struct UnionFind
{

  int n;
  vector<int> size, par;

  UnionFind(int a)
  {
    n = a;
    size.assign(n, 1);
    par.resize(n);
    for (int i = 0; i < n; i++)
    {
      par[i] = i;
    }
  }

  int find(int x)
  {
    if (par[x] == x)
      return x;
    return par[x] = find(par[x]);
  }

  void merge(int x, int y)
  {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty)
      return;
    if (size[rootx] > size[rooty])
    {
      size[rootx] += size[rooty];
      par[rooty] = rootx;
    }
    else
    {
      size[rooty] += size[rootx];
      par[rootx] = rooty;
    }
  }
};
class Solution
{
public:
  int minCostConnectPoints(vector<vector<int>> &points)
  {

    int n = points.size();
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        edges.push_back({wt, i, j});
      }
    }

    UnionFind uf = UnionFind(n);
    sort(edges.begin(), edges.end());
    int totalCost = 0;
    int count = 0;
    for (auto v : edges)
    {
      int cost = v[0];
      int x = v[1];
      int y = v[2];

      if (uf.find(x) != uf.find(y))
      {
        uf.merge(x, y);
        totalCost += cost;
        count += 1;
      }

      if (count == n - 1)
        break;
    }

    return totalCost;
  }
};