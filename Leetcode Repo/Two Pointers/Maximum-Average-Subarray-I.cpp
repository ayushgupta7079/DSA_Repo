1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4        
5        int sum = -1e9;
6        int n = nums.size();
7
8        int curSum = 0;
9
10        for(int head=0; head<n ; head++){
11            curSum += nums[head];
12
13            if(head >= k-1){
14                sum = max(sum, curSum);
15                int tail = head-k+1;
16                curSum -= nums[tail];
17            }
18        }
19
20        return (double)sum/k;
21    }
22};