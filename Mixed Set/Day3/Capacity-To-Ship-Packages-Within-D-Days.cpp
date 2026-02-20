1class Solution {
2public:
3    bool check(int mid, vector<int>& w, int days){
4
5        int cur = 0;
6        int count = 1;
7
8        for(auto v : w){
9            cur += v;
10
11            if(cur > mid){
12                count++;
13                cur = v;
14            }
15            if(count > days) return false;
16        }
17
18        return 1;
19    }
20
21    int shipWithinDays(vector<int>& weights, int days) {
22        
23        int n = weights.size();
24        int lo = *max_element(weights.begin(), weights.end());
25        int hi = accumulate(weights.begin(), weights.end(), 0);
26
27        int ans = hi;
28
29        while(lo <= hi){
30            int mid = lo + (hi-lo)/2;
31
32            if(check(mid, weights, days)){
33                ans = mid; 
34                hi = mid-1;
35            }
36            else lo = mid+1;
37        }
38        return ans;
39    }
40};