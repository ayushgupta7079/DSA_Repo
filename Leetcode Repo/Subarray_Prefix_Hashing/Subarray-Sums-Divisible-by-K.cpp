1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        
5        int pref = 0;
6        int ans = 0;
7        unordered_map<int,int> mp;
8        mp[0]=1;
9
10        for(int i=0;i<nums.size();i++){
11            pref += nums[i];
12            int rem =( (pref%k) + k )%k;
13
14            ans += mp[rem];
15            mp[rem]++;
16        }
17        return ans;
18    }
19};