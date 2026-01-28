1class Solution {
2public:
3    int numberOfArithmeticSlices(vector<int>& nums) {
4        
5        int n = nums.size();
6        if(n < 3) return 0;
7
8        int ans = 0;
9        int count = 0;
10
11        for(int i=2;i <n;i++){
12            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
13                count++;
14                ans += count;
15            }
16            else{
17                count = 0;
18            }
19        }
20
21        return ans;
22
23    }
24};