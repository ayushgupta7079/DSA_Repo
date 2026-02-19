1class Solution {
2public:
3    bool check(int mid, vector<int>& nums, int m, int k){
4
5        int count = 0;
6        int n = nums.size();
7        int l = 0;
8        for(int i=0;i<n;i++){
9            if(nums[i] <= mid){
10                l++;
11            }
12            else l=0;
13
14            if(l == k) {
15                count++;
16                l = 0;
17            }
18            if(count >= m) return 1;
19        }
20        return 0;
21    }
22    int minDays(vector<int>& bloomDay, int m, int k) {
23        
24
25        int n = bloomDay.size();
26        if(n < 1ll*m*k) return -1;
27
28        int lo = 1;
29        int hi = 0;
30        for(auto v : bloomDay) hi = max(hi, v);
31
32        int ans =-1;
33
34        while(lo <= hi){
35            int mid = lo + (hi-lo)/2;
36            if(check(mid, bloomDay, m, k)){
37                ans = mid;
38                hi = mid-1;
39            }
40            else{
41                lo = mid+1;
42            }
43        }
44
45        return ans;
46    }
47};