1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        
5        int n = nums.size();
6        // ponters
7        int head=-1;
8        int tail = 0;
9
10        // dat structure
11        int zeroes = 0;
12        int ans = 0;
13        
14        while(tail < n){
15
16            // expand
17            while(head+1<n && ((nums[head+1] == 0 && zeroes < k) || (nums[head+1] == 1 && zeroes <= k))){
18                head++;
19                // update DS
20                if(nums[head]==0) zeroes++;
21            }
22
23            ans = max(ans, head - tail + 1);
24
25            // Shrink
26            if(head < tail){
27                tail++;
28                head = tail-1;
29
30            }
31            else{
32                if(nums[tail]==0) zeroes--;
33                tail++;
34            }
35        }
36
37        return ans;
38    }
39};