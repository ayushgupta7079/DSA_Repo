1class Solution {
2public:
3    bool check(int mid, vector<int>& pos, int m){
4        int placed = 0;
5        int last = -1e9;
6        int n = pos.size();
7        for(int i=0;i<n;i++){
8            if(pos[i] - last >= mid){
9                placed++;
10                last = pos[i];
11            }
12            if(placed >= m) return true;
13        }
14        return false;
15    }
16    int maxDistance(vector<int>& pos, int m) {
17        int n = pos.size();
18        sort(pos.begin(), pos.end());
19        int lo = 0;
20        int hi = pos[n-1] - pos[0];
21
22        while(lo <= hi){
23            int mid = lo + (hi-lo)/2;
24            if(check(mid, pos, m)){
25                lo = mid+1;
26            }
27            else{
28                hi = mid-1;
29            }
30        }
31        return hi;
32    }
33};