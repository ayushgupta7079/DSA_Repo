class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {

    int n = nums.size();
    vector<int> lis, insertedAt(n);

    for (int i = 0; i < n; i++)
    {

      if (lis.empty() || lis.back() < nums[i])
      {
        lis.push_back(nums[i]);
        insertedAt[i] = lis.size();
      }
      else
      {
        int it = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
        lis[it] = nums[i];
        insertedAt[i] = it + 1;
      }
    }
    return lis.size();
    int curlen = lis.size();
    vector<int> finalLis;
    for (int i = n - 1; i >= 0; i--)
    {
      if (insertedAt[i] == curlen)
      {
        finalLis.push_back(nums[i]);
        curlen--;
      }
    }
  }
};