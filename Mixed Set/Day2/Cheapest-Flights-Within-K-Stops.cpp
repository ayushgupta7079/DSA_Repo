1class Solution {
2public:
3    #define F first
4    #define S second
5    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
6        
7        vector<vector<pair<int,int>>> g(n);
8
9        for(auto x : flights){
10            g[x[0]].push_back({x[1],x[2]});
11        }
12
13        vector<vector<int>> dist(n, vector<int> (k+2,1e9));
14        dist[src][0]=0;
15
16        priority_queue<pair<pair<int,int>, int>> pq; // {{dist, k}, node}
17        pq.push({{0,0},src});
18
19        while(!pq.empty()){
20            auto state = pq.top();
21            pq.pop();
22            int node = state.S;
23            int stops = state.F.S;
24            if(stops >= k+1) continue;
25
26            for(auto [neigh, cost] : g[node]){
27                if(dist[neigh][stops+1] > dist[node][stops] + cost){
28                    dist[neigh][stops+1] = dist[node][stops] + cost;
29                    pq.push({{-dist[neigh][stops+1], (stops+1)}, neigh});
30                }
31            }
32        }
33
34        int ans = 1e9;
35        for(int i=0;i<=k+1;i++){
36            // cout<<dist[dst][i]<<endl;
37            ans = min(ans, dist[dst][i]);
38        }
39
40        return ans == 1e9 ? -1 : ans;
41    }
42};