1class Solution {
2public:
3    vector<int> getAverages(vector<int>& nums, int k) {
4        
5        int kk = 2*k;
6        int n = nums.size();
7        vector<int> avg(n,-1);
8        long long sum = 0;
9
10        for(int i=0;i<n;i++){
11
12            sum += nums[i];
13
14            if(i >= kk+1){
15                sum -= nums[i - kk - 1];
16            }
17            if(i >= kk){
18                int j = i - k;
19                avg[j] = (sum)/(kk+1);
20            }
21        }
22
23        return avg;
24    }
25};