1class Solution {
2public:
3    int maxScore(vector<int>& nums, int k) {
4        int sum = 0;
5        for(auto v : nums) sum += v;
6        int n = nums.size();
7        int curSum = 0;
8        int ans = 1e9;
9
10        for(int head=0; head<n;head++){
11
12            curSum += nums[head];
13            if(n - k - 1 >= 0 && head >= n - k - 1){
14                ans = min(ans, curSum);
15                curSum -= nums[head-n+k+1];
16            }
17        }
18        
19        return ans == 1e9 ? sum : sum-ans;
20    }
21};