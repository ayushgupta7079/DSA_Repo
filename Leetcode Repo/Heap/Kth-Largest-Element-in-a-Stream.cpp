1class KthLargest {
2public:
3    priority_queue<int, vector<int>, greater<int>> pq;
4    int x;
5    KthLargest(int k, vector<int>& nums) {
6        x = k;
7        int n = nums.size();
8        for(auto v : nums){
9            pq.push(v);
10
11            if(pq.size() > k){
12                pq.pop();
13            }
14        }
15    }
16    
17    int add(int val) {
18        
19        
20        pq.push(val);
21        if(pq.size() > x) pq.pop();
22        return pq.top();
23    }
24};
25
26/**
27 * Your KthLargest object will be instantiated and called as such:
28 * KthLargest* obj = new KthLargest(k, nums);
29 * int param_1 = obj->add(val);
30 */