1class Solution {
2public:
3    int minFlips(string s) {
4        
5        string t = s + s;
6        int n = s.length(); 
7        int m = 2*n;
8
9        int ans = 1e9;
10
11        int diff1=0, diff2=0;
12        for(int head=0; head<m; head++){
13
14            char ch = t[head];
15            if(head%2==0){
16                if(ch =='0') diff2++;
17                else diff1++;
18            }
19            else{
20                if(ch =='0') diff1++;
21                else diff2++;
22            }
23
24            if(head >= n){
25                int tail = head-n;
26                char rem=t[tail];
27                if(tail%2==0){
28                    if(rem =='0') diff2--;
29                    else diff1--;
30                }
31                else{
32                    if(rem =='0') diff1--;
33                    else diff2--;
34                }
35            }
36            if(head >= n-1){
37                ans = min({ans, diff1, diff2});
38            }
39        }
40
41        return ans;
42    }
43};