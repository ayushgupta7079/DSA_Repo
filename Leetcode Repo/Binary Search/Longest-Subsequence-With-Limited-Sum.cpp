1class Solution {
2public:
3    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6
7        for(int i=1;i<n;i++){
8            nums[i] += nums[i-1];
9        }
10
11        vector<int> ans;
12        for(int i=0;i<queries.size();i++){
13            int x = queries[i];
14            int ind = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
15            ans.push_back(ind);
16        }
17        return ans;
18    }
19};