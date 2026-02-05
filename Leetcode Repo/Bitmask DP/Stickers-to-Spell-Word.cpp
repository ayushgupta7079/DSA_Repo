1class Solution {
2public:
3    int n;
4    int m;
5    int dp[51][(1<<15) + 5];
6    int rec(int level, int mask, vector<string>& st, string &target){
7
8        if(level == n){
9            if (mask == ((1 << m)-1)) return 0;
10            else return 1e9;
11        }
12
13        if(dp[level][mask]!=-1) return dp[level][mask];
14
15        int ans = 1e9;
16        ans = min(ans, rec(level+1, mask, st, target));
17        int temp = mask;
18        for(auto v : st[level]){
19            for(int i = 0; i< m; i++){
20                if(target[i] == v && ((temp & (1 << i)) == 0)){
21                    temp |= (1<<i);
22                    break;
23                }
24            }
25        }
26        if(temp != mask)ans = min(ans, 1 + rec(level, temp, st, target));
27        
28
29        return dp[level][mask]=ans;
30    }
31    int minStickers(vector<string>& stickers, string target) {
32        
33        n = stickers.size();
34        m = target.size();
35
36        memset(dp,-1,sizeof(dp));
37
38        int ans =  rec(0,0, stickers, target);
39
40        return ans == 1e9 ? -1 : ans;
41    }
42};