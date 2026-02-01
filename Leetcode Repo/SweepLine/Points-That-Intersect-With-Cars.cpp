1class Solution {
2public:
3    int numberOfPoints(vector<vector<int>>& nums) {
4        
5        int n = nums.size();
6        vector<vector<int>> events;
7
8        for(auto v : nums){
9            events.push_back({v[0],-1});
10            events.push_back({v[1],+1});
11        }
12
13        sort(events.begin(), events.end());
14
15        int ans = 0;
16        int cnt = 0;
17        int st = -1;
18
19        for(int i = 0; i <2*n; i++){
20            
21            if(cnt == 0){
22                st = events[i][0];
23            }
24
25            cnt += events[i][1];
26
27            if(cnt == 0){
28
29                // cout<<st << " "<<events[i][0]<<endl;
30                ans += events[i][0] - st + 1;
31            }
32
33        }
34
35        return ans;
36    }
37};