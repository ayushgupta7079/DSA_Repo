1class Solution {
2public:
3    bool repeatedSubstringPattern(string s) {
4        
5        int n = s.length();
6
7        vector<int> lps(n+1);
8        lps[0]=-1;
9        int i=0, j=-1;
10
11        while(i < n){
12
13            while(j!=-1 && s[i]!= s[j]) j = lps[j];
14            i++;
15            j++;
16            lps[i]=j;
17        }
18
19        return lps[n] != 0 && n % (n - lps[n]) == 0;
20    }
21};