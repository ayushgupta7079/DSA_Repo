1class Solution {
2public:
3    vector<vector<int>> subsets(vector<int>& nums) {
4        
5        int n = nums.size();
6
7        vector<vector<int>> ans;
8
9        for(int mask=0;mask<(1<<n);mask++){
10            vector<int> temp;
11            for(int i=0; i <n;i++){
12                if((mask>>i)&1){
13                    temp.push_back(nums[i]);
14                }
15            }
16
17            ans.push_back(temp);
18        }
19        return ans;
20    }
21};