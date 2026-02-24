1class Solution {
2public:
3    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
4        
5        priority_queue<pair<double,int>> pq;
6        vector<double> dist(n, 0);
7        dist[start_node]= 1.0;
8        pq.push({1, start_node});
9
10        vector<vector<pair<int, double>>> g(n);
11        int i=0;
12        for(auto e : edges){
13            g[e[0]].push_back({e[1],succProb[i]});
14            g[e[1]].push_back({e[0],succProb[i]});
15            i++;
16        }
17
18        while(!pq.empty()){
19            auto [d, node] = pq.top();
20            pq.pop();
21
22            if(d < dist[node]) continue;
23
24            for(auto v : g[node]){
25                auto [neigh, w] = v;
26                if(dist[neigh] < dist[node]*w){
27                    dist[neigh] = dist[node]*w;
28                    pq.push({dist[neigh], neigh});
29                }
30            }
31        }
32
33        return dist[end_node];
34    }
35};