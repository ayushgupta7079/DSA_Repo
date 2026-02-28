1class Solution {
2public:
3    string shortestPalindrome(string s) {
4        
5        int m = s.length();
6        if(m==0) return s;
7        string t = s;
8        reverse(t.begin(), t.end());
9        string str = s + "#" + t;
10        int n = str.length();
11        vector<int> lps(n+1);
12        lps[0]=-1;
13
14        int i=0,j=-1;
15
16        while(i < n){
17            while(j !=-1 && str[i]!=str[j]) j = lps[j];
18            i++;
19            j++;
20            lps[i] = j;
21        }
22
23        int len =  m - lps.back();
24        string req = s.substr(m-len);
25        // cout<<req<<endl;
26        reverse(req.begin(), req.end());
27
28        return req + s;
29    }
30};