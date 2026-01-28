1class Solution {
2public:
3    bool check(int mid, vector<int>& nums, int k){
4
5        int count=1;
6        int sum = 0;
7        int n = nums.size();
8        for(int i=0;i<n;i++){
9            if(sum + nums[i] <= mid){
10                sum += nums[i];
11            }
12            else{
13                count++;
14                sum = nums[i];
15            }
16
17        }
18        return count <= k;
19    }
20    int splitArray(vector<int>& nums, int k) {
21        
22        int n = nums.size();
23        int lo = *max_element(nums.begin(), nums.end());
24        int hi = accumulate(nums.begin(), nums.end(),0);
25        cout<<lo <<" "<<hi<<endl;
26        int ans =-1;
27
28        while(lo <= hi){
29            int mid = lo + (hi-lo)/2;
30
31            if(check(mid, nums, k)){
32                ans = mid;
33                hi = mid-1;
34            }
35            else{
36                lo = mid+1;
37            }
38        }
39
40        return ans;
41
42
43    }
44};