class Solution
{
public:
  int m, n;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};
  void dfs(vector<vector<int>> &image, int x, int y, int color, int org_col)
  {

    image[x][y] = color;
    for (int k = 0; k < 4; k++)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (nx < 0 || ny < 0 || nx >= m || ny >= n || image[nx][ny] != org_col)
        continue;

      dfs(image, nx, ny, color, org_col);
    }
  }
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    m = image.size();
    n = image[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int org_col = image[sr][sc];
    if (org_col == color)
      return image;
    dfs(image, sr, sc, color, org_col);
    return image;
  }
};