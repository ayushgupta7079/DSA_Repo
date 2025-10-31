/*
778. Swim in Rising Water
https://leetcode.com/problems/swim-in-rising-water/description/
*/

/*
Solution 1 :  Dijkstra
*/
class Solution
{
public:
  int swimInWater(vector<vector<int>> &grid)
  {

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    while (!pq.empty())
    {
      auto node = pq.top();
      int h = -node.first;
      int x = node.second.first;
      int y = node.second.second;
      pq.pop();

      for (int k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        int nh = grid[nx][ny];
        int newMax = max(h, nh);
        if (dist[nx][ny] > newMax)
        {
          dist[nx][ny] = newMax;
          pq.push({-dist[nx][ny], {nx, ny}});
        }
      }
    }

    return dist[n - 1][m - 1];
  }
};

/*
Solution 2 : DSU
*/

struct DSU
{

  int n;
  vector<int> size, par;
  DSU(int a)
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
  int swimInWater(vector<vector<int>> &grid)
  {

    int n = grid.size();
    DSU uf = DSU(n * n);
    vector<vector<int>> arr(n * n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        arr[grid[i][j]] = {i, j};
      }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    vector<int> dist(n * n, 1e9);

    for (int i = 0; i < n * n; i++)
    {
      for (int k = 0; k < 4; k++)
      {

        int nx = arr[i][0] + dx[k];
        int ny = arr[i][1] + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
          continue;
        if (grid[nx][ny] < i)
        {
          uf.merge(grid[nx][ny], i);
          if (uf.find(grid[0][0]) == uf.find(grid[n - 1][n - 1]))
            return i;
        }
      }
    }
    return 0;
  }
};