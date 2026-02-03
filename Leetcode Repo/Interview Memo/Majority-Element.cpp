1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        
5        int cnt =0, cand = 0;
6
7        for(auto v : nums){
8            if(cnt == 0){
9                cand = v;
10                cnt++;
11            }
12            else if(cand == v)cnt++;
13            else cnt--;
14        }
15
16        return cand;
17    }
18};