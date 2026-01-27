1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        
5        int n = s.length();
6        int m = p.length();
7        if(n < m) return {};
8        vector<int> prr(26,0);
9        vector<int> ans;
10
11        for(auto v : p){
12            prr[v-'a']++;
13        }
14
15        for(int head=0; head<n; head++){
16
17            prr[s[head]-'a']--;
18
19            if(head >= m){
20                prr[s[head-m]-'a']++;
21            }
22
23            if(head >= m-1){
24
25                bool ana = true;
26
27                for(int i=0;i<26;i++){
28                    if(prr[i]!=0) {
29                        ana = false; 
30                        break;
31                    }
32                }
33
34                if(ana) ans.push_back(head-m+1);
35            }
36        }
37        return ans;
38    }
39};