1class Solution {
2public:
3    int fillCups(vector<int>& amount) {
4        
5        priority_queue<int> pq;
6
7        for(auto v : amount){
8            if(v!=0)pq.push(v);
9        }
10        int ans = 0;
11        while(!pq.empty()){
12
13            if(pq.size() == 1){
14                ans += pq.top();
15                pq.pop();
16            }
17            else{
18                int x = pq.top();pq.pop();
19                int y = pq.top();pq.pop();
20                if(x > 1)pq.push(x-1);
21                if(y > 1)pq.push(y-1);
22
23                ans += 1;
24            }
25        }
26        return ans;
27    }
28};