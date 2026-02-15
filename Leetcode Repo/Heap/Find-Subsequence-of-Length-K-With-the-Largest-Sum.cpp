1class Solution {
2public:
3    vector<int> maxSubsequence(vector<int>& nums, int k) {
4        
5        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
6
7        for(int i=0;i<nums.size();i++){
8            pq.push({nums[i],i});
9            if(pq.size() > k) pq.pop();
10        }
11
12        vector<pair<int,int>> arr;
13        while(!pq.empty()){
14            arr.push_back({pq.top().second, pq.top().first});
15            pq.pop();
16        }
17
18        sort(arr.begin(), arr.end());
19        vector<int> result;
20
21        for(auto v : arr){
22            result.push_back(v.second);
23        }
24        return result;
25    }
26};