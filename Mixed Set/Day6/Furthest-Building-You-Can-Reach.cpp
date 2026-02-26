1class Solution {
2public:
3    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
4        priority_queue<int, vector<int>, greater<>> pq;
5        int n = heights.size();
6        for(int i=1;i<n;i++){
7            
8            if(heights[i] - heights[i-1] > 0){
9                pq.push(heights[i] - heights[i-1]);
10                if(pq.size() > ladders){
11                    int x = pq.top();
12                    pq.pop();
13                    bricks -= x;
14
15                    if(bricks < 0) return i-1;
16                }
17            }
18        }
19
20        return n-1;
21    }
22};