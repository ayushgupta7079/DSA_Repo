1class Solution {
2public:
3    int maximumUniqueSubarray(vector<int>& nums) {
4        
5        int n = nums.size();
6        int head=-1;
7        int tail=0;
8        int sum = 0;
9        int ans = 0;
10        unordered_map<int,bool> mp;
11
12        while(tail < n){
13            while(head + 1 < n && mp[nums[head+1]]==0){
14                head++;
15                sum += nums[head];
16                mp[nums[head]]=1;
17            }
18
19            ans = max(ans, sum);
20            if(tail>head){
21                tail++;
22                head=tail-1;
23            }
24            else{
25                sum-=nums[tail];
26                mp[nums[tail]]=0;
27                tail++;
28            }
29        }
30        return ans;
31    }
32};