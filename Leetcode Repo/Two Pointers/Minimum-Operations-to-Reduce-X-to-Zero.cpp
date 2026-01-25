1class Solution {
2public:
3    int helper(vector<int> & nums, int target){
4        int head = -1, tail = 0;
5        int n = nums.size();
6        int ans = -1;
7        int curSum = 0;
8        while(tail < n){
9            while(head+1 < n && curSum + nums[head+1] <= target){
10                head++;
11                curSum += nums[head];
12            }
13            if(curSum == target)ans = max(ans,head-tail+1);
14
15            if(tail > head){
16                tail++;
17                head = tail-1;
18            }
19            else{
20                curSum -= nums[tail];
21                tail++;
22            }
23        }
24
25        return ans;
26    }
27    int minOperations(vector<int>& nums, int x) {
28        
29        int n = nums.size();
30        int sum = 0;
31        for(auto v : nums) sum += v;
32        x = sum-x;
33
34        int ans1 = helper(nums,x);
35        return ans1==-1?-1:n-ans1;
36        
37    }
38};