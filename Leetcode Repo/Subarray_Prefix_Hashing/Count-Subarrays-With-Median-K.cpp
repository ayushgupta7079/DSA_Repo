1class Solution {
2public:
3    int countSubarrays(vector<int>& nums, int k) {
4        
5        int sum =0, ans =0;
6        unordered_map<int,int> mp;
7        int pos;
8        mp[0]=1;
9        for(int i=0;i<nums.size();i++){
10            if(nums[i] == k) {pos = i;break;}
11        }
12
13        for(int i=pos+1;i<nums.size();i++){
14            sum += (nums[i] > k) ? 1 : (nums[i] == k) ? 0 : -1;
15            mp[sum]++;
16        }
17        sum = 0;
18        for(int i =pos;i>=0;i--){
19            sum += (nums[i] > k) ? 1 : (nums[i] == k) ? 0 : -1;
20
21            ans += mp[-sum];
22            ans += mp[1-sum];
23        }
24
25        return ans;
26    }
27};