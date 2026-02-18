1class Solution {
2public:
3
4    long long helper(vector<int>& nums, int k){
5
6        int n = nums.size();
7        int tail = 0;
8        int head = -1;
9        int distinct = 0;
10        unordered_map<int,int> mp;
11        long long ans = 0;
12
13        while(tail < n){
14            while(head + 1 < n && (distinct < k || mp[nums[head + 1]])){
15                head++;
16                if(mp[nums[head]]==0) distinct++;
17                mp[nums[head]]++;
18            }
19
20            ans += (head - tail + 1);
21
22            if(tail > head){
23                tail++;
24                head = tail-1;
25            }
26            else{
27                mp[nums[tail]]--;
28                if(mp[nums[tail]]==0) distinct--;
29                tail++;
30            }
31        }
32
33        return ans;
34    }
35    int subarraysWithKDistinct(vector<int>& nums, int k) {
36        
37        long long atmostK = helper(nums, k);
38        long long atmostkminus1 = helper(nums, k-1);
39        return int(atmostK - atmostkminus1);
40    }
41};