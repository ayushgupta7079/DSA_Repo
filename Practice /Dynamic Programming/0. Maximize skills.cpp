#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> t, s;

int rec(int i, int slots, int tleft)
{

  if (i == 0)
  {
    if (slots > 0 && tleft >= t[0])
    {
      return max(0, s[0]);
    }
    return 0;
  }

  return max(rec(i - 1, slots, tleft), s[i] + rec(i - 1, slots - 1, tleft - t[i]));
}
void solve()
{
  int T;
  cin >> n >> k >> T;
  t.resize(n);
  s.resize(n);

  for (int i = 0; i < n; i++)
  {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  cout << rec(n - 1, k, T);
}

int main()
{
  solve();
}