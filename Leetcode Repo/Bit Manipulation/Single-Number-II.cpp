1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        
5        int ans = 0;
6        int n = nums.size();
7        for(int i=0;i<32;i++){
8            int count=0;
9            for(int j=0;j<n;j++){
10                count += (nums[j] >> i) & 1;
11
12            }
13
14            count %= 3;
15            if(count)ans |= (1<<i);
16        }
17
18        return ans;
19    }
20};