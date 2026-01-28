1class Solution {
2public:
3    bool check(int mid, int n, int m, int k){
4        int count = 0;
5
6        for(int i=1;i<=n;i++){
7            count += min(m, mid/i);
8        }
9
10        return count >= k;
11    }
12    int findKthNumber(int m, int n, int k) {
13        
14        int lo = 1;
15        int hi = n*m;
16        int ans =-1;
17
18        while(lo <= hi){
19            int mid = lo + (hi-lo)/2;
20
21            if(check(mid, n, m, k)){
22                ans = mid;
23                hi= mid-1;
24            }
25            else{
26                lo = mid+1;
27            }
28        }
29
30        return ans;
31    }
32};