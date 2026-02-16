1class Solution {
2public:
3    vector<int> numberGame(vector<int>& nums) {
4        priority_queue<int, vector<int>, greater<int>> pq;
5
6        for(auto v : nums){
7            pq.push(v);
8        }   
9
10        vector<int> arr;
11        while(!pq.empty()){
12            int a = pq.top();
13            pq.pop();
14            int b = pq.top();
15            pq.pop();
16
17            arr.push_back(b);
18            arr.push_back(a);
19        }
20
21        return arr;
22    }
23};