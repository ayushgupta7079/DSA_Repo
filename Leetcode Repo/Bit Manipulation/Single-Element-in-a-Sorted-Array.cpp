1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4        int xr=0;
5        for(auto v : nums){
6            xr ^= v;
7        }
8        return xr;
9    }
10};