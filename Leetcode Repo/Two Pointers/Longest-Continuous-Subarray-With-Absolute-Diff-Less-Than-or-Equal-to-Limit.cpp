1class Solution {
2public:
3    bool valid(deque<int> &dq1, deque<int>& dq2, int limit, int head, vector<int>& nums){
4
5        if(dq1.empty()) return 1;
6        else if(abs(dq2.front() - nums[head]) <= limit && abs(dq1.front() - nums[head]) <= limit) return 1;
7        else return 0;
8       
9    }
10    int longestSubarray(vector<int>& nums, int limit) {
11        
12        int n = nums.size();
13        int head=-1;
14        int tail=0;
15        int ans =0;
16        deque<int> dq1,dq2;
17
18        while(tail<n){
19
20            while(head+1<n && valid(dq1, dq2, limit, head+1, nums)){
21                head++;
22                while(!dq1.empty() && dq1.back() < nums[head]) dq1.pop_back();
23                while(!dq2.empty() && dq2.back() > nums[head]) dq2.pop_back();
24                dq1.push_back(nums[head]);
25                dq2.push_back(nums[head]);
26            }
27
28            ans = max(ans, head-tail+1);
29
30            if(tail > head){
31                tail++;
32                head=tail-1;
33            }
34            else{
35                if(dq1.front() == nums[tail]) dq1.pop_front();
36                if(dq2.front() == nums[tail]) dq2.pop_front();
37                tail++;
38            }
39        }
40        return ans;
41    }
42};