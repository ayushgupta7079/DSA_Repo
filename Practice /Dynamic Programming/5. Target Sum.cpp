#include <bits/stdc++.h>
using namespace std;

int n;
int dp[205][10010]; // dp[level][sum]
vector<int> arr;

int rec(int level, int sum_left)
{
  if (sum_left < 0)
    return 0; // pruning

  if (level == n) // base
    return (sum_left == 0);

  if (dp[level][sum_left] != -1)
    return dp[level][sum_left];

  int take = rec(level + 1, sum_left - arr[level]);
  int not_take = rec(level + 1, sum_left);

  return dp[level][sum_left] = take + not_take;
}

void print_solution(int level, int sum_left)
{
  if (level == n)
    return;

  int take = 0;
  if (sum_left - arr[level] >= 0)
    take = rec(level + 1, sum_left - arr[level]);

  int not_take = rec(level + 1, sum_left);

  if (take)
  {
    cout << arr[level] << " ";
    print_solution(level + 1, sum_left - arr[level]);
  }
  else if (not_take)
  {
    print_solution(level + 1, sum_left);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int q;
  cin >> q;

  while (q--)
  {
    int target;
    cin >> target;

    // Reset dp for this query
    memset(dp, -1, sizeof(dp));

    int ways = rec(0, target);
    cout << "Ways: " << ways << "\n";

    if (ways > 0)
    {
      cout << "Subset: ";
      print_solution(0, target);
      cout << "\n";
    }
    else
    {
      cout << "No subset found\n";
    }
    cout << "------------------\n";
  }
}
