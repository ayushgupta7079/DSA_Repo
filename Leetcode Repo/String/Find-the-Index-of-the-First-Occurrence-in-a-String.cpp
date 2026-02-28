1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int m = needle.length();
5        
6        string s = needle + "#" + haystack;
7        int n= s.length();
8        vector<int> lps(n+1);
9        lps[0] = -1;
10
11        int i=0,j=-1;
12
13        while(i < n){
14            while(j!=-1 && s[i] != s[j]) j = lps[j];
15            i++;
16            j++;
17            lps[i] = j;
18            if(lps[i] == m) return i-2*m-1;
19        }
20        return -1;
21    }
22};