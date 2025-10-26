/*
684. Redundant Connection
https://leetcode.com/problems/redundant-connection/description/
*/

struct UnionFind
{
  int n;
  vector<int> size, par;

  UnionFind(int a)
  {
    n = a;
    size.assign(n + 1, 1);
    par.resize(n + 1);
    for (int i = 1; i <= n; i++)
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
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {

    int n = edges.size();
    UnionFind uf = UnionFind(n);
    for (auto v : edges)
    {
      int x = v[0];
      int y = v[1];

      if (uf.find(x) != uf.find(y))
      {
        uf.merge(x, y);
      }
      else
      {
        return {x, y};
      }
    }
    return {0, 0};
  }
};