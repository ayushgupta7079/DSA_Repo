1class Solution {
2public:
3    int findMaxLength(vector<int>& nums) {
4        int ans = 0;
5        int prefSum = 0;
6        unordered_map<int,int> mp;
7        mp[0]=-1;
8
9        for(int i=0;i<nums.size();i++){
10            prefSum += (nums[i]==1)?1:-1;
11
12            if(mp.find(prefSum) != mp.end()){
13                ans = max(ans, i - mp[prefSum]);
14            }
15
16            if(mp.find(prefSum) == mp.end())mp[prefSum]=i;
17        }
18
19        return ans;
20    }
21};