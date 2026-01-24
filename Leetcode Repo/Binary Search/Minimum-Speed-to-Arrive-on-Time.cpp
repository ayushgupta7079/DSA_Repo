1class Solution {
2public:
3    int n;
4    bool check(int mid, vector<int> &dist, double hour){
5
6        double time = 0;
7
8        for(int i=0;i < n-1; i++){
9
10            int temp = (dist[i] + mid-1)/mid;
11            time += 1.0*temp;
12        }
13
14        time += (1.0*dist[n-1])/mid;
15        return time <= hour;
16    }
17    int minSpeedOnTime(vector<int>& dist, double hour) {
18        
19        n = dist.size();
20        int lo = 1, hi = 1e9;
21        int ans=-1;
22        while(lo <= hi){
23            int mid = lo + (hi-lo)/2;
24            if(check(mid, dist, hour)){
25                ans = mid;
26                hi = mid-1;
27            }
28            else{
29                lo = mid+1;
30            }
31        }
32        return (int)ans;
33    }
34};