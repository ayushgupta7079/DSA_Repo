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
18        int i=0,j=0;
19        while(i < m && j < st[level].size()){
20            if(target[i] == st[level][j]){
21                if((temp & (1 << i)) == 0){
22                    temp |= (1<<i);
23                    i++;
24                    j++;
25                }
26                else i++;
27            }
28            else if(target[i] > st[level][j]) j++;
29            else i++;
30        }
31        if(temp != mask)ans = min(ans, 1 + rec(level, temp, st, target));
32        
33
34        return dp[level][mask]=ans;
35    }
36    int minStickers(vector<string>& stickers, string target) {
37        
38        n = stickers.size();
39        m = target.size();
40
41        memset(dp,-1,sizeof(dp));
42        for(auto &v : stickers){
43            sort(v.begin(), v.end());
44        }
45
46        sort(target.begin(), target.end());
47
48        int ans =  rec(0,0, stickers, target);
49
50        return ans == 1e9 ? -1 : ans;
51    }
52};