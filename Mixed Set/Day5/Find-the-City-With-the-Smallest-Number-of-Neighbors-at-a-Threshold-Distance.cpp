1class Solution {
2public:
3    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
4        
5        vector<vector<int>> dist(n, vector<int>(n, 1e9));
6        for(int i=0;i<n;i++) dist[i][i]=0;
7        for(auto v : edges){
8            dist[v[0]][v[1]] = min(dist[v[0]][v[1]], v[2]);
9            dist[v[1]][v[0]] = min(dist[v[1]][v[0]], v[2]);
10        }
11
12        for(int via=0; via<n; via++){
13            for(int i=0;i<n;i++){
14                for(int j=0;j<n;j++){
15                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
16                }
17            }
18        }
19
20        int city = -1;
21        int count = n;
22        for(int i=0;i<n;i++){
23            int cur = 0;
24            for(int j=0; j<n;j++){
25                if(j!=i && dist[i][j] <= distanceThreshold){
26                    cur++;
27                }
28            }
29
30            if(cur <= count){
31                city = i;
32                count = cur;
33            }
34        }
35
36        return city;
37    }
38};