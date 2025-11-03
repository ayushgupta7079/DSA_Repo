/*
827. Making A Large Island
https://leetcode.com/problems/making-a-large-island/
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
    int rx = find(x);
    int ry = find(y);

    if (rx == ry)
      return;
    if (size[rx] >= size[ry])
    {
      size[rx] += size[ry];
      par[ry] = rx;
    }
    else
    {
      size[ry] += size[rx];
      par[rx] = ry;
    }
  }
};

class Solution
{
public:
  int largestIsland(vector<vector<int>> &grid)
  {

    int m = grid.size();
    int n = m * m;

    UnionFind uf = UnionFind(n);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!grid[i][j])
          continue;
        int node = m * i + j;
        for (int k = 0; k < 4; k++)
        {
          int ni = i + dx[k];
          int nj = j + dy[k];
          int neigh = m * ni + nj;
          // valid check
          if (ni < 0 || nj < 0 || ni >= m || nj >= m)
            continue;

          if (grid[ni][nj])
          {
            uf.merge(node, neigh);
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      // only root will be checked because other values can be incorrect
      if (uf.find(i) == i)
        ans = max(ans, uf.size[i]);
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int node = m * i + j;
        if (!grid[i][j])
        {
          int sz = 0;
          map<int, bool> mp;

          for (int k = 0; k < 4; k++)
          {
            int ni = i + dx[k];
            int nj = j + dy[k];
            int neigh = m * ni + nj;

            // valid check
            if (ni < 0 || nj < 0 || ni >= m || nj >= m || grid[ni][nj] == 0)
              continue;

            // finding root
            int r = uf.find(neigh);
            if (!mp[r])
            {
              sz += uf.size[r];
              mp[r] = 1;
            }
          }
          ans = max(ans, sz + 1);
        }
      }
    }
    return ans;
  }
};