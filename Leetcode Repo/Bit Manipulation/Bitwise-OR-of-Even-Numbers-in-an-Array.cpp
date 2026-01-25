1class Solution {
2public:
3    int evenNumberBitwiseORs(vector<int>& nums) {
4        
5        int xr=0;
6        for(auto v : nums){
7            if(v%2==0) xr|=v;
8        }
9        return xr;
10    }
11};