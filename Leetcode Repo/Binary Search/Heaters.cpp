1class Solution {
2public:
3    bool check(int mid, vector<int>& h, vector<int>& heat, int n, int m){
4        int l=1e9+7,r=-1;
5        vector<int> p(n+1,0);
6        for(int i=0;i<m;i++){
7            int left = heat[i] - mid;
8            int right = heat[i] + mid;
9
10            int ind1 = lower_bound(h.begin(), h.end(), left) - h.begin();
11            int ind2 = upper_bound(h.begin(), h.end(), right) - h.begin();
12
13            if(ind1!=n){
14                p[ind1]+=1;
15            }
16            p[ind2]-=1;
17        }
18        for(int i=0;i<n;i++){
19            if(i)p[i] += p[i-1];
20            if(p[i]<=0) return 0;
21        }
22        return 1;
23    }
24    int findRadius(vector<int>& h, vector<int>& heat) {
25        
26        int n = h.size();
27        int m = heat.size();
28        sort(h.begin(), h.end());
29        sort(heat.begin(), heat.end());
30        int lo = 0;
31        int hi = INT_MAX; 
32        int ans = -1;
33
34        while(lo <= hi){
35            int mid = lo + (hi-lo)/2;
36            if(check(mid, h, heat, n, m)){
37                ans = mid;
38                hi = mid-1;
39            }
40            else{
41                lo = mid+1;
42            }
43        }
44        return ans;
45    }
46};