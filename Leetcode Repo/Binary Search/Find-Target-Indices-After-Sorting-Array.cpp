1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        
5        int ind = 0;
6        int k = 0;
7        for(int i=0;i<nums.size();i++){
8            if(nums[i] == target) {
9                k++;
10            }
11            if(nums[i] < target) ind++;
12        }
13        vector<int> ans;
14        for(int i = ind;i<ind+k; i++){
15            ans.push_back(i);
16        }
17        return ans;
18    }
19};