1class Solution {
2public:
3    vector<vector<int>> merge(vector<vector<int>>& intervals) {
4        
5        vector<vector<int>> ans;
6        int n = intervals.size();
7
8        vector<vector<int>> events;
9
10        for(auto v : intervals){
11            events.push_back({v[0],-1});
12            events.push_back({v[1],+1});
13        }
14
15        sort(events.begin(), events.end());
16
17        int cnt = 0;
18        int st = -1;
19
20        for(int i=0; i<2*n; i++){
21            
22            if(cnt == 0){
23                st = events[i][0];   // start of a merged interval
24            }
25
26            cnt += events[i][1];
27
28            if(cnt == 0){
29                ans.push_back({st, events[i][0]}); // end of merged interval
30            }
31        }
32
33        return ans;
34    }
35};