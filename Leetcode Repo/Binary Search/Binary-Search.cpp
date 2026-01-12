1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int lo = 0;
6        int hi = n-1;
7        while(lo <= hi){
8            int mid = lo + (hi-lo)/2;
9            if(nums[mid] == target) return mid;
10            else if(nums[mid] > target) hi = mid-1;
11            else lo = mid+1;
12        }
13
14        return -1;  
15    }
16};