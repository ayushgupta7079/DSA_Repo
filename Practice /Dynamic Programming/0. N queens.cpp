#include <bits/stdc++.h>
using namespace std;
int n;
bool check(int x, int y, vector<int> &queens)
{

  for (int r = 0; r < x; r++)
  {
    int c = queens[r];
    if (y == c)
      return 0; // same column
    if (abs(r - x) == abs(c - y))
      return 0; // diagonal
  }
  return 1;
}
vector<vector<string>> ans;
void rec(int row, vector<vector<int>> &grid, vector<int> &queens)
{

  if (row == n)
  {
    vector<string> str(n);
    string s = "";
    for (int i = 0; i < n; i++)
    {
      s += '.';
    }
    for (int i = 0; i < n; i++)
    {
      int c = queens[i];
      string temp = s;
      temp[c] = 'Q';
      str[i] = temp;
    }

    ans.push_back(str);
    return;
  }

  for (int col = 0; col < n; col++)
  {
    if (check(row, col, queens))
    {
      grid[row][col] = 1;
      queens[row] = col;
      rec(row + 1, grid, queens);
      grid[row][col] = 0;
      queens[row] = -1;
    }
  }
  return;
}
void solve()
{

  cin >> n;
  vector<int> queens(n, -1);
  vector<vector<int>> grid(n, vector<int>(n, 0));

  rec(0, grid, queens);

  for (auto v : ans)
  {
    for (auto s : v)
    {
      cout << s << " ";
    }
    cout << endl;
  }
}
int main()
{
  solve();
}