1class Solution {
2public:
3    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
4        vector<int> freq(50, 0);
5        vector<int> ans;
6
7        int n = nums.size();
8
9        for (int i = 0; i < n; i++) {
10            if (nums[i] < 0)
11                freq[-nums[i] - 1]++;
12
13            if (i >= k - 1) {
14                int cnt = 0;
15                int beauty = 0;
16
17                for (int j = 49; j >= 0; j--) {
18                    cnt += freq[j];
19                    if (cnt >= x) {
20                        beauty = -(j + 1);
21                        break;
22                    }
23                }
24
25                ans.push_back(beauty);
26
27                if (nums[i - k + 1] < 0)
28                    freq[-nums[i - k + 1] - 1]--;
29            }
30        }
31
32        return ans;
33    }
34};
35