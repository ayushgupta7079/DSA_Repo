1class Solution {
2public:
3    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
4        
5        int n = mat.size();
6        int m = mat[0].size();
7        priority_queue<pair<int,int>> pq;
8        for(int i=0;i<n;i++){
9            int sold = 0;
10            for(int j=0;j<m;j++){
11                sold += mat[i][j];
12            }
13            pq.push({sold, i});
14
15            if(pq.size() > k) pq.pop();
16        }
17        vector<int> result;
18
19        while(!pq.empty()){
20            result.push_back(pq.top().second);
21            pq.pop();
22        }
23
24        reverse(result.begin(), result.end());
25        return result;
26
27    }
28};