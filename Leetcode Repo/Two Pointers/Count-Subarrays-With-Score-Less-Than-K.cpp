1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, long long k) {
4        
5        int n = nums.size();
6        int head=-1, tail=0;
7        long long sum = 0;
8        long long ans = 0;
9
10        while(tail < n){
11            while(head+1 < n && (sum + nums[head+1]) *(head-tail+2) < k){
12                head++;
13                sum += nums[head];
14            }
15            ans += head-tail+1;
16
17            if(tail > head){
18                tail++;
19                head = tail-1;
20            }
21            else{
22                sum -= nums[tail];
23                tail++;
24            }
25        }
26        return ans;
27    }
28};  