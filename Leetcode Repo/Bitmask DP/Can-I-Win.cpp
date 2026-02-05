1class Solution {
2public:
3    int dp[(1<<20)+5];
4    int n, total;
5
6    int rec( int sum, int mask){
7
8        if(sum >= total) return 0;
9
10        if(dp[mask]!=-1) return dp[mask];
11
12        int ans = 0;
13
14        for(int i=0 ; i< n; i++){
15            if(mask & (1ll << i)) continue;
16
17            if(rec(sum + i + 1,mask | (1 << i)) == 0){
18                ans = 1;
19            }
20        }
21        return dp[mask] = ans;
22    }
23    bool canIWin(int maxChoosableInteger, int desiredTotal) {
24        n = maxChoosableInteger;
25        total = desiredTotal;
26        if(total==0) return 1;
27        if(n*(n+1)/2 < total) return 0;
28
29        memset(dp,-1,sizeof(dp));
30
31        return rec(0,0);
32    }
33};