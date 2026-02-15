1class Solution {
2public:
3    int lastStoneWeight(vector<int>& stones) {
4        
5        int n = stones.size();
6        priority_queue<int> pq;
7
8        for(auto v : stones) pq.push(v);
9
10        while(pq.size()!=1){
11            int y = pq.top();
12            pq.pop();
13            int x = pq.top();
14            pq.pop();
15
16            if(x != y){
17                pq.push(y - x);
18            }
19            else{
20                if(pq.empty()) return 0;
21            }
22        }
23        return pq.top();
24    }
25};