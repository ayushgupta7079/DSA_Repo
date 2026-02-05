1class Solution {
2public:
3    int n, target, subset;
4    int dp[(1<<(17))+5];
5
6    bool rec(int mask, int sum, int s, vector<int>& nums){
7
8        if(sum > target || s > subset) return 0;
9        if(mask == ((1 << n)-1)){
10            return s == subset && sum == 0;
11        }
12
13        if(dp[mask]!=-1) return dp[mask];
14
15        int ans = 0;
16
17        for(int i=0; i<n; i++){
18            if(mask & (1 << i)) continue;
19
20            if((sum + nums[i]) == target) ans |= rec(mask|(1<<i) ,0,s+1, nums);
21            else ans |= rec(mask|(1<<i) ,sum + nums[i],s, nums);
22
23        }
24
25        return dp[mask]=ans;
26    }
27    bool canPartitionKSubsets(vector<int>& nums, int k) {
28        n = nums.size();
29        for(auto v : nums) target += v;
30        if(target%k) return false;
31        target /= k;
32        subset = k;
33
34        memset(dp,-1,sizeof(dp));
35        return rec(0,0,0, nums);
36    }
37};