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
15                
16                if(nums[i] + nums[j] + nums[k] <= target){
17                    sum = (nums[i] + nums[j] + nums[k]);
18                    i++;
19                }
20                else{
21                    sum = (nums[i] + nums[j] + nums[k]);
22                    k--;
23                }
24                if(abs(target- sum) < minm){
25                    ans = sum;
26                    minm = abs(target - sum);
27                }
28            }
29
30        }
31        return ans;
32    }
33};