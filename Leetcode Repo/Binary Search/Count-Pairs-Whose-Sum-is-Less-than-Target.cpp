1class Solution {
2public:
3    int countPairs(vector<int>& nums, int target) {
4        int cnt = 0;
5        sort(nums.begin(),nums.end());
6
7        int l =0;
8        int h = nums.size()-1;
9
10        while(l<h){
11
12            if(nums[l]+nums[h]<target){
13                cnt += h-l;
14                l++;
15            }
16            else{
17                h--;
18            }
19        }
20        return cnt;
21    }
22};