1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        
5        int n = nums.size();
6        int head=-1;
7        int tail=0;
8        long long sum = 0;
9        int ans  = n+1;
10
11        while(tail < n){
12            while(head+1 < n && sum < target){
13                head++;
14                sum += nums[head];
15            }
16            if(sum >= target)ans = min(ans, head- tail +1);
17
18            if(tail > head){
19                tail++;
20                head = tail-1;
21            }
22            else{
23                sum -= nums[tail];
24                tail++;
25            }
26        }
27
28        return ans!=n+1 ? ans:0;
29    }
30};