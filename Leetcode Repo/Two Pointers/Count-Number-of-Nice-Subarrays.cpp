1class Solution {
2public:
3    int helper(vector<int>& nums, int k){
4        int n = nums.size();
5        int head=-1;
6        int tail=0;
7        int ans=0;
8        int count=0;
9
10        while(tail<n){
11            while(head+1<n && (count < k || nums[head+1]%2==0)){
12                head++;
13                if(nums[head]%2==1) count++;
14            }
15
16            ans += (head-tail+1);
17
18            if(tail > head){
19                tail++;
20                head=tail-1;
21            }
22            else{
23                if(nums[tail]%2) count--;
24                tail++;
25            }
26        }
27        return ans;
28
29    }
30    int numberOfSubarrays(vector<int>& nums, int k) {
31        return helper(nums,k) - helper(nums,k-1);
32    }
33};