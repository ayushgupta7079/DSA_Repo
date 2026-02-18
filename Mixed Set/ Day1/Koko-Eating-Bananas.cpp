1class Solution {
2public:
3    bool check(int mid, vector<int>& piles, int h){
4        long long time = 0;
5
6        for(auto v : piles){
7            time += (1ll*v + mid -1)/mid;
8            if(time > h) return false;
9        }
10
11        return time <= h;
12    }
13    int minEatingSpeed(vector<int>& piles, int h) {
14        
15        int n = piles.size();
16        int lo = 1;
17        int hi = -1;
18        for(auto v: piles) hi = max(hi,v);
19        int ans;
20
21        while(lo <= hi){
22            int mid = lo + (hi-lo)/2;
23
24            if(check(mid, piles, h)){
25                ans = mid;
26                hi = mid-1;
27            }
28            else{
29                lo = mid+1;
30            }
31        }
32        return ans;
33    }
34};