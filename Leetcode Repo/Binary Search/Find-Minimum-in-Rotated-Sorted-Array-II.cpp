1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        
5        int n = nums.size();
6        int lo = 0;
7        int hi = n-1;
8
9        int i = lo;
10        while(i < n-1 && nums[i]==nums[i+1]){
11            i++;
12        }
13        lo = i;
14        i = n-1;
15        while(i > 0 && nums[i]==nums[i-1]){
16            i--;
17        }
18        hi = i;
19        int ans = lo;
20
21        cout<<lo<<" "<<hi<<endl;
22        while(lo <= hi){
23            int mid = lo+ (hi-lo)/2;
24            if(nums[mid] < nums[0]){
25                ans = mid;
26                hi = mid-1;
27
28                // cout<<"ans :"<<ans<<endl;
29            }
30            else{
31                lo = mid+1;
32            }
33        }
34
35        return nums[ans];
36    }
37};