1class Solution {
2public:
3    string minWindow(string s, string t) {
4        
5        unordered_map<char,int> mpt;
6        for(auto v : t){
7            mpt[v]++;
8        }
9
10        map<char,int> mps;
11        int head=-1;
12        int tail =0 ;
13        int ans = 1e9;
14        int n = s.length();
15        int m = mpt.size();
16        int count = 0;
17        int l,r;
18
19        while(tail < n){
20            while(head+1 < n && count < m){
21                head++;
22                mps[s[head]]++;
23                if(mps[s[head]] == mpt[s[head]]) count++;
24            }
25
26            if(count == m){
27                if(ans > head-tail +1){
28                    l = tail;
29                    r = head;
30                    ans = head-tail+1;
31                }
32            }
33
34            if(tail > head){
35                tail++;
36                head = tail-1;
37            }
38            else{
39                mps[s[tail]]--;
40                if(mps[s[tail]] < mpt[s[tail]]) count--;
41                tail++;
42            }
43        }
44
45        
46        return ans == 1e9 ? "" : s.substr(l,r-l+1);
47    }
48};