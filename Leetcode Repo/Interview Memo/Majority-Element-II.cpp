1class Solution {
2public:
3    vector<int> majorityElement(vector<int>& nums) {
4        int n = nums.size();
5        int cnt1=0, cnt2=0;
6        int cand1=0, cand2=0;
7
8        for(auto v : nums){
9
10            if(v == cand1){
11                cnt1++;
12            }
13            else if(v == cand2){
14                cnt2++;
15            }
16            else if(cnt1 == 0){
17                cand1 = v;
18                cnt1++;
19            }
20            else if(cnt2 == 0){
21                cand2 = v;
22                cnt2++;
23            }
24            else {
25                cnt1--;
26                cnt2--;
27            }
28        }
29
30        cnt1=0,cnt2=0;
31        for(auto v : nums){
32            if(v == cand1) cnt1++;
33            else if(v == cand2) cnt2++;
34        }
35
36        vector<int> ans;
37        if(cnt1 > n/3) ans.push_back(cand1);
38        if(cnt2 > n/3) ans.push_back(cand2);
39
40        return ans;
41    }
42};