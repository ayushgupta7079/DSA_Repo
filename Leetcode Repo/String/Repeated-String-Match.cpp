1class Solution {
2public:
3    bool helper(string a, string b, int rep){
4        int n = b.length();
5        int m = a.length();
6        string ra = "";
7        for(int i=0;i<rep;i++){
8            ra += a;
9        }
10        string s = b + "#" + ra;
11        int l = s.length();
12        vector<int> lps(l+1);
13        lps[0] = -1;
14        int i=0,j=-1;
15
16        while(i < l){
17            while( j!= -1 && s[i] != s[j]) j = lps[j];
18            i++;
19            j++;
20            lps[i] = j;
21
22            if(lps[i] == n) return 1;
23        }
24        return 0;
25    }
26    int repeatedStringMatch(string a, string b) {
27        int n = b.length();
28        int m = a.length();
29        int rep = (n + m - 1)/m;
30        int ans1 = helper(a,b,rep);
31        int ans2 = helper(a,b,rep+1);
32        if(ans1) return rep;
33        else if(ans2) return rep+1;
34        else return -1;
35    }
36};