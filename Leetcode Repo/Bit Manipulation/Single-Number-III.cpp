1class Solution {
2public:
3    vector<int> singleNumber(vector<int>& nums) {
4        
5        long long xorOfAll = 0;
6        for(auto v : nums){
7            xorOfAll ^= v;
8        }
9        int a=0, b=0;
10        long long diffBit = xorOfAll & (~xorOfAll + 1);
11
12        for(auto v : nums){
13            if(diffBit & v){
14                a ^= v;
15            }
16            else{
17                b ^= v;
18            }
19        }
20        return {a,b};
21    }
22};