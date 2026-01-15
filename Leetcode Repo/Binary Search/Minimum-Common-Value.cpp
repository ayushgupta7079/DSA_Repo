1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        int i = 0;
5        int j = 0;
6        int n = nums1.size();
7        int m = nums2.size();
8
9        while(i < n && j < m){
10            if(nums1[i] == nums2[j]) return nums1[i];
11            else if(nums1[i] < nums2[j]) i++;
12            else j++;
13        }
14        return -1;
15    }
16};