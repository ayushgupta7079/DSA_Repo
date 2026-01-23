1class Solution {
2public:
3    int threeSumClosest(vector<int>& nums, int target) {
4        
5        int ans=1e9;
6        int n = nums.size();
7        sort(nums.begin(), nums.end());
8        int minm=1e9;
9
10        for(int j=0;j<n;j++){
11            int i=0;
12            int k=n-1;
13            int sum = 0;
14            while(i < j && j < k){
15                sum = (nums[i] + nums[j] + nums[k]);
16
17                if(sum <= target){
18                    i++;
19                }
20                else{
21                    k--;
22                }
23                if(abs(target- sum) < minm){
24                    ans = sum;
25                    minm = abs(target - sum);
26                }
27            }
28
29        }
30        return ans;
31    }
32};