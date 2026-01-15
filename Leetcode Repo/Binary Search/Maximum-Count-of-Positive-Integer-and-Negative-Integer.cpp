1class Solution {
2public:
3    int maximumCount(vector<int>& nums) {
4        int n = nums.size();
5        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
6        int pos = n - (lower_bound(nums.begin(), nums.end(), 1) - nums.begin());
7        return max(pos,neg);
8    }
9};