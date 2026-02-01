1class Solution {
2public:
3    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
4        
5        vector<int> arr(1001, 0);
6
7        for(auto v : items1){
8            arr[v[0]] += v[1];
9        }
10        for(auto v : items2){
11            arr[v[0]] += v[1];
12        }
13
14        vector<vector<int>> ans;
15
16        for(int i=1;i<=1000;i++){
17            if(arr[i] > 0){
18                ans.push_back({i, arr[i]});
19            }
20        }
21
22        return ans;
23    }
24};