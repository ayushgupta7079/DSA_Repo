1class Solution {
2public:
3    string longestPrefix(string s) {
4        
5        int n = s.length();
6
7        vector<int> lps(n+1,0);
8        lps[0] = -1;
9        int i=0, j=-1;
10        
11        while(i < n){
12            while(j!=-1 && s[i] != s[j]) j = lps[j];
13            i++;
14            j++;
15            lps[i] = j;
16        }
17
18        int len = lps[n];
19        string ans = s.substr(n-len);
20        return ans;
21    }
22};