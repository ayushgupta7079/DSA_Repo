1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        
5        int n = s.length();
6        int head = -1;
7        int tail = 0;
8        int ans = 0;
9
10        unordered_map<char,int> mp;
11
12        while(tail < n){
13
14            // expand
15            while(head+1 < n && mp[s[head+1]] == 0){
16                head++;
17                // update ds
18                mp[s[head]]=1;
19            }
20            ans = max(ans, head-tail+1);
21
22            if(tail > head){
23                tail++;
24                head = tail -1 ;
25            }
26            else{
27                // update ds
28                mp[s[tail]]=0;
29                tail++;
30            }
31        }
32
33        return ans;
34    }
35};