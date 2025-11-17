
#include <bits/stdc++.h>
using namespace std;

int rec(int level)
{
  if (level < 0)
    return 0;
  if (level == 0)
    return 1;

  return rec(level - 1) + rec(level - 2) + rec(level - 3);
}
void solve()
{

  int N;
  cin >> N;

  cout << rec(N);
}

int main()
{
  solve();
}
