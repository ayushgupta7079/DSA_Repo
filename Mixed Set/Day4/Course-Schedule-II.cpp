1class Solution {
2public:
3    vector<int> findOrder(int n, vector<vector<int>>& pr) {
4        
5        vector<vector<int>> g(n);
6        vector<int> indeg(n,0);
7
8        for(auto v : pr){
9            g[v[1]].push_back(v[0]);
10            indeg[v[0]]++;
11        }
12
13        queue<int> q;
14
15        for(int i=0;i<n;i++){
16            if(indeg[i] == 0) q.push(i);
17        }
18
19        vector<int> order;
20        while(!q.empty()){
21            int c = q.front();
22            q.pop();
23
24            order.push_back(c);
25
26            for(auto v : g[c]){
27                indeg[v]--;
28
29                if(indeg[v] == 0) q.push(v);
30            }
31        }
32
33        if(order.size() != n) return {};
34        else return order;
35    }
36};