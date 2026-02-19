1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        
5        int n = s.length();
6        int head=-1;
7        int tail = 0;
8        int ans = 0;
9
10        vector<int> mp(26,0);
11        int maxFreq = 0;
12
13        while(tail < n){
14
15            while(head + 1 < n && ((head - tail + 2 - maxFreq) <= k || mp[s[head+1]-'A'] == maxFreq)){
16                head++;
17                mp[s[head]-'A']++;
18                maxFreq = max(maxFreq, mp[s[head]-'A']);
19            }
20
21            ans = max(ans, head-tail + 1);
22
23            if(tail > head){
24                tail++;
25                head = tail-1;
26            }
27            else{
28                // update
29                mp[s[tail]-'A']--;
30                tail++;
31            }
32        }
33
34        return ans;
35    }
36};