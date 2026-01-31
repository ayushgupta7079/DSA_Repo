1class Solution {
2public:
3    int dp[23][2][2][410];
4    int minsum, maxsum;
5    int m;
6    int mod = 1e9+7;
7
8    int rec(int level, int tlo, int thi, int cursum, string &s1, string &s2){
9        if(cursum > maxsum) return 0;
10        if(level == m){
11            if(cursum >= minsum) return 1;
12            else return 0;
13        }
14
15        if(dp[level][tlo][thi][cursum]!=-1) return dp[level][tlo][thi][cursum];
16
17        int ans = 0;
18        int lo=0,hi=9;
19
20        lo = tlo ? s1[level]-'0' : 0;
21        hi = thi ? s2[level]-'0' : 9;
22
23        for(int i=lo; i <= hi; i++){
24            int ntlo = tlo, nthi=thi;
25            if(i!=(s1[level]-'0')) ntlo = 0;
26            if(i!=(s2[level]-'0')) nthi = 0;
27
28            ans += rec(level+1, ntlo, nthi, cursum + i, s1, s2);
29            ans %= mod;
30        } 
31        return dp[level][tlo][thi][cursum]=ans;
32    }
33    
34    int count(string num1, string num2, int min_sum, int max_sum) {
35        
36        memset(dp,-1,sizeof(dp));
37        int n = num1.length();
38        m = num2.length();
39        minsum = min_sum;
40        maxsum = max_sum;
41
42        string temp="";
43        while(n < m){
44            temp += "0";
45            n++;
46        }
47
48        num1 = temp + num1;
49        memset(dp,-1,sizeof(dp));
50        return rec(0,1,1,0, num1, num2);
51    }   
52};