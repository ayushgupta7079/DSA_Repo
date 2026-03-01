1class Solution {
2public:
3    string preprocess(string &s){
4        int n = s.length();
5        string ret;
6        ret.reserve(2*n + 3);
7        ret += "^";
8        for(int i=0;i<n;i++){
9            ret += '#';
10            ret += s[i];
11        }
12        ret += "#$";
13        // cout<<ret<<endl;
14        return ret;
15    }
16    int countSubstrings(string s) {
17        
18        string T = preprocess(s);
19        int n = T.length();
20        vector<int> P(n);
21        int C=0, R=0;
22        for(int i=1;i<n-1;i++){
23            int i_mirror = 2*C-i;
24
25            if(i < R){
26                P[i] = min(R-i, P[i_mirror]);
27            }
28            else{
29                P[i]=0;
30            }
31
32            while(T[i+1+P[i]] == T[i-1-P[i]]){
33                P[i]++;
34            }
35
36            if(i+P[i] > R){
37                C = i;
38                R = i + P[i];
39            }
40
41            // cout<<"i :"<<P[i]<<endl;
42        }
43
44        int ans = 0;
45
46        for(int i=1;i<n-1;i++){
47            if(P[i]%2==0) ans += P[i]/2;
48            else ans += (P[i] + 1)/2;
49        }
50
51        return ans;
52    }
53};