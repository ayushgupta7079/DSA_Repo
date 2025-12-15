#include <bits/stdc++.h>
using namespace std;

// LIS NLOGN
void solve()
{

  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> lis, insertedAt(n);
  for (int i = 0; i < n; i++)
  {

    if (lis.empty() || lis.back() < arr[i])
    {
      lis.push_back(arr[i]);
      insertedAt[i] = lis.size();
    }
    else
    {
      int it = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
      lis[it] = arr[i];
      insertedAt[i] = it + 1;
    }
  }

  int ans = lis.size();
  vector<int> final_lis;
  // return;
  int cur_len = ans;
  for (int i = n - 1; i >= 0; i--)
  {
    if (insertedAt[i] == cur_len)
    {
      final_lis.push_back(arr[i]);
      cur_len--;
    }
  }
  cout << "LIS :" << ans << endl;
  reverse(final_lis.begin(), final_lis.end());
  cout << "Solution : ";
  for (auto v : final_lis)
  {
    cout << v << " ";
  }
}
int main()
{

  int t = 1;
  // cin>>t;
  while (t--)
    solve();
}