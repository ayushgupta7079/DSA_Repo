1class Solution {
2public:
3    bool check(int mid, vector<int>& h, vector<int>& heat, int n, int m){
4        int i=0,j=0;
5
6        while(i < n && j<m){
7            if(abs(h[i]-heat[j]) <= mid) i++;
8            else j++;
9        }
10
11        return i == n;
12    }
13    int findRadius(vector<int>& h, vector<int>& heat) {
14        
15        int n = h.size();
16        int m = heat.size();
17        sort(h.begin(), h.end());
18        sort(heat.begin(), heat.end());
19        int lo = 0;
20        int hi = INT_MAX; 
21        int ans = -1;
22
23        while(lo <= hi){
24            int mid = lo + (hi-lo)/2;
25            if(check(mid, h, heat, n, m)){
26                ans = mid;
27                hi = mid-1;
28            }
29            else{
30                lo = mid+1;
31            }
32        }
33        return ans;
34    }
35};