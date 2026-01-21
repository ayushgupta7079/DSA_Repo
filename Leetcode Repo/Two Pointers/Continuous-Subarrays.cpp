1class Solution {
2public:
3    bool valid(int head, deque<int> &dq1, deque<int> &dq2, vector<int>& nums){
4
5        if(dq1.empty()) return 1;
6        else if(abs(dq1.front() - nums[head]) <= 2 && abs(dq2.front() - nums[head]) <= 2) return 1;
7        else return 0;
8    }
9    long long continuousSubarrays(vector<int>& nums) {
10        int n = nums.size();
11        int head=-1;
12        int tail=0;
13        deque<int> dq1;
14        deque<int> dq2;
15        long long ans=0;
16
17        while(tail < n){
18            while(head+1<n && valid(head+1, dq1, dq2, nums)){
19                head++;
20                while(!dq1.empty() && dq1.back() < nums[head]) dq1.pop_back();
21                while(!dq2.empty() && dq2.back() > nums[head]) dq2.pop_back();
22
23                dq1.push_back(nums[head]);
24                dq2.push_back(nums[head]);
25            }
26
27            ans += (head-tail+1);
28
29            if(tail>head){
30                tail++;
31                head=tail-1;
32            }
33            else{
34                if(dq1.front() == nums[tail]) dq1.pop_front();
35                if(dq2.front() == nums[tail]) dq2.pop_front();
36                tail++;
37            }
38        }
39        return ans;
40    }
41};