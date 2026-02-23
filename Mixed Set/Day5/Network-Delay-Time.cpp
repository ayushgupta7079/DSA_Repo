1class Solution {
2public:
3    using ii = pair<int,int>;
4    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
5        
6        vector<vector<pair<int,int>>> g(n+1);
7        for(auto v : times){
8            g[v[0]].push_back({v[1], v[2]});
9        }
10
11        vector<int> dist(n+1, 1e9);
12        priority_queue<ii, vector<ii>, greater<>> pq;
13        pq.push({0,k});
14        dist[k] = 0;
15
16        while(!pq.empty()){
17            auto [d, node] = pq.top();
18            pq.pop();
19
20            if(dist[node] < d) continue;
21
22            for(auto v : g[node]){
23                auto [neigh, w] = v;
24                if(dist[neigh] > dist[node] + w){
25                    dist[neigh] = dist[node] + w;
26                    pq.push({dist[neigh], neigh});
27                }
28            }
29        }
30
31        int ans = -1e9;
32        for(int i=1;i<=n;i++){
33            ans = max(ans, dist[i]);
34        }
35
36        return ans == 1e9 ? -1 : ans;
37    }
38};