1class Solution {
2public:
3    bool check(int mid, vector<int>& nums){
4        int ind = lower_bound(nums.begin(), nums.end(), mid) -  nums.begin();
5        int count = (int)nums.size() - ind;
6
7        return count >= mid;
8    }
9    int specialArray(vector<int>& nums) {
10        sort(nums.begin(), nums.end());
11        int n = nums.size();
12        int lo = 0;
13        int hi = nums.back();
14        int ans = -1;
15
16        while(lo <= hi){
17            int mid = lo + (hi-lo)/2;
18            if(check(mid,nums)){
19                ans = mid;
20                lo = mid+1;
21            }
22            else{
23                hi = mid-1;
24            }
25        }
26        int ind = lower_bound(nums.begin(), nums.end(), ans) -  nums.begin();
27        return (n - ind == ans) ? ans : -1;
28    }
29};