1class Solution {
2public:
3    char findTheDifference(string s, string t) {
4        
5        int xr = 0;
6        for(auto v : s){
7            xr ^= (v - 'a');
8        }
9        for(auto v : t){
10            xr ^= (v-'a');
11        }
12
13        return 'a' + xr;
14    }
15};