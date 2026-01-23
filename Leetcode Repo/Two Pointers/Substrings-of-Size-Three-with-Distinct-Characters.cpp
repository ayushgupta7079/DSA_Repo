1class Solution {
2public:
3    int countGoodSubstrings(string s) {
4        
5        vector<int> freq(26,0);
6        int n = s.length();
7
8        int ans = 0;
9        int dist = 0;
10
11        for(int head=0; head<n ;head++){
12
13            freq[s[head]-'a']++;
14            if(freq[s[head]-'a']==1) dist++;
15
16            if(head >= 2){
17                if(dist == 3) ans++;
18
19                int tail = head-2;
20                freq[s[tail]-'a']--;
21                if(freq[s[tail]-'a']==0) dist--;
22            }
23        }
24        return ans;
25    }
26};