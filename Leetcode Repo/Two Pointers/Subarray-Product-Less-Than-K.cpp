1class Solution {
2public:
3    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
4        
5        int n = nums.size();
6        int head=-1;
7        int tail=0;
8        int ans =0;
9        long long prod = 1;
10        while(tail < n){
11            while(head+1<n && prod*nums[head+1] < k){
12                head++;
13                prod *= nums[head];
14            }
15
16            ans += (head-tail+1);
17
18            if(tail > head){
19                tail++;
20                head=tail-1;
21            }
22            else{
23                prod /= nums[tail];
24                tail++;
25            }
26        }
27        return ans;
28    }
29};