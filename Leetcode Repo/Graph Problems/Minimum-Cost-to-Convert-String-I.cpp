1class Solution {
2public:
3    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
4        
5
6        vector<vector<long long>> dist(26,vector<long long>(26,1e18));
7
8        for(int i=0;i<original.size();i++){
9            int u = original[i]-'a';
10            int v = changed[i]-'a';
11
12            dist[u][v] = min(dist[u][v],1ll*cost[i]);
13        }
14
15        for(int i=0;i<26;i++) dist[i][i]=0;
16
17        for(int via=0; via<26; via++){
18            for(int i=0; i<26;i++){
19                for(int j=0; j<26;j++){
20                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
21                }
22            }
23        }
24
25        long long minCost = 0;
26        for(int i=0;i<source.length();i++){
27            int u = source[i]-'a';
28            int v = target[i]-'a';
29            if( dist[u][v] == 1e18) return -1;
30            minCost += dist[u][v];
31        }
32
33        return minCost;
34    }
35};