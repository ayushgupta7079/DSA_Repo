1class Solution {
2public:
3
4
5    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
6       int n = s.length();
7       int ans =0;
8       int len = minSize;
9       int k = maxLetters;
10
11       vector<int> freq(26,0);
12       unordered_map<string, int> mp;
13       int dist = 0;
14       for(int head=0; head<n; head++){
15            int ch = s[head]-'a';
16            freq[ch]++;
17            if(freq[ch]==1) dist++;
18
19            if(head >= len){
20                freq[s[head-len]-'a']--;
21                if(freq[s[head-len]-'a']==0) dist--;
22            }
23
24            if(head >= len-1 && dist <= k){
25                int tail = head-len+1;
26                string temp = s.substr(tail, len);
27                ans = max(ans, ++mp[temp]);
28            }
29       }
30        return ans;
31    }
32};