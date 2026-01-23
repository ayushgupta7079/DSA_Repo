1class Solution {
2public:
3    vector<vector<int>> fourSum(vector<int>& nums, int target) {
4        int n = nums.size();
5        vector<vector<int>> res;
6        if (n < 4) return res;
7
8        sort(nums.begin(), nums.end());
9
10        for (int i = 0; i < n - 3; i++) {
11            if (i > 0 && nums[i] == nums[i - 1]) continue;
12
13            for (int j = i + 1; j < n - 2; j++) {
14                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
15
16                long long rem = (long long)target - nums[i] - nums[j];
17                int l = j + 1, r = n - 1;
18
19                while (l < r) {
20                    long long sum = nums[l] + nums[r];
21
22                    if (sum == rem) {
23                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
24
25                        while (l < r && nums[l] == nums[l + 1]) l++;
26                        while (l < r && nums[r] == nums[r - 1]) r--;
27
28                        l++;
29                        r--;
30                    } 
31                    else if (sum < rem) {
32                        l++;
33                    } 
34                    else {
35                        r--;
36                    }
37                }
38            }
39        }
40        return res;
41    }
42};
43