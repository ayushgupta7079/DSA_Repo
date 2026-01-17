1class Solution {
2public:
3    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
4        
5        int n = difficulty.size();
6
7        vector<pair<int,int>> arr;
8        for(int i=0;i<n;i++){
9            arr.push_back(make_pair(difficulty[i], profit[i]));
10        }
11
12        sort(arr.begin(),arr.end());
13
14        unordered_map<int,int> mp;
15
16        for(int i=0;i<n;i++){
17            int diff = arr[i].first;
18            int prof = arr[i].second;
19
20            mp[diff] = max(mp[diff], prof);
21            if(i) {
22                mp[diff] = max(mp[diff], mp[arr[i-1].first]);
23            }
24        }
25
26        sort(difficulty.begin(), difficulty.end());
27        int ans = 0;
28        for(int i=0;i<worker.size();i++){
29            int capacity = worker[i];
30            int ind = upper_bound(difficulty.begin(), difficulty.end(),capacity) - difficulty.begin();
31
32            if(ind!=0){
33                ans += mp[difficulty[ind-1]];
34            }
35        }
36
37        return ans;
38    }
39};