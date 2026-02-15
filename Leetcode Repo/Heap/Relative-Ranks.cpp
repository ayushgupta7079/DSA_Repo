1class Solution {
2public:
3    vector<string> findRelativeRanks(vector<int>& score) {
4        
5        priority_queue<pair<int,int>> pq;
6        int n = score.size();
7        for(int i=0;i<n;i++){
8            pq.push({score[i],i});
9        }
10
11        vector<string> result(n);
12        int rank = 1;
13        while(!pq.empty()){
14            int pos = pq.top().second;
15            if(rank == 1){
16                result[pos] = "Gold Medal";
17            }
18            else if(rank == 2){
19                result[pos] = "Silver Medal";
20            }
21            else if(rank == 3){
22                result[pos] = "Bronze Medal";
23            }
24            else {
25                result[pos] = to_string(rank);
26            }
27
28            pq.pop();
29            rank++;
30        }
31
32        return result;
33    }
34};