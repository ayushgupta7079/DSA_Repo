1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
4        
5
6        vector<vector<int>> events;
7        for(auto v : intervals){
8            events.push_back({v[0],-1});
9            events.push_back({v[1],+1});
10        }
11
12        events.push_back({newInterval[0],-1});
13        events.push_back({newInterval[1],1});
14        sort(events.begin(), events.end());
15
16        vector<vector<int>> ans;
17        int cnt = 0;
18        int st = -1;
19
20        for(int i=0; i<events.size(); i++){
21
22            if(cnt == 0){
23                st = events[i][0];
24            }
25
26            cnt += events[i][1];
27
28            if(cnt == 0){
29                ans.push_back({st, events[i][0]});
30            }
31        }
32
33        return ans;
34    }
35};