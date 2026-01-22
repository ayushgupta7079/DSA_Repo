1class Solution {
2public:
3    int helper(vector<int>& nums, int goal){
4        int n = nums.size();
5        int head=-1;
6        int tail=0;
7        int ans = 0;
8        int sum =0 ;
9
10        while(tail < n){
11            while(head+1<n && (sum + nums[head+1] <= goal)){
12                head++;
13                sum += nums[head];
14            }
15
16            ans += (head-tail+1);
17            if(tail>head){
18                tail++;
19                head=tail-1;
20            }
21            else{
22                sum -= nums[tail];
23                tail++;
24            }
25        }
26        return ans;
27    }
28    int numSubarraysWithSum(vector<int>& nums, int goal) {
29        return helper(nums, goal) - helper(nums, goal-1);
30    }
31};