1class Solution {
2public:
3    bool check(int x,int n){
4        long long  coin_needed = 1ll*x*(x+1)/2;
5        return coin_needed <= n;
6    }
7    int arrangeCoins(int n) {
8        
9        int lo = 1;
10        int hi = n;
11
12        int ans = -1;
13        while(lo <= hi){
14            int mid = lo + (hi-lo)/2;
15
16            if(check(mid,n)){
17                ans = mid;
18                lo = mid+1;
19            }
20            else{
21                hi = mid-1;
22            }
23        }
24        return ans;
25    }
26};