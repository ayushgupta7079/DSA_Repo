1class Solution {
2public:
3    bool check(vector<int>& nums,int mid){
4        return nums[mid] < nums[0] ;
5    }
6    int pivot(vector<int>& nums){
7        int n = nums.size();
8        int lo= 0;
9        int hi=n-1;
10        int ans = 0;
11        while(lo<=hi){
12            int mid = lo + (hi-lo)/2;
13            if(check(nums,mid)){
14                ans = mid;
15                hi = mid-1;
16            }
17            else lo = mid+1;
18        }
19        return ans;
20    }
21    
22    int search(vector<int>& nums, int target) {
23        
24        int n = nums.size();
25        if(n==1){
26            if(nums[0]==target)return 0;
27            return -1;
28        }
29
30        int x = pivot(nums);
31        cout<<x<<endl;
32        int lo = 0;
33        int hi = x-1;
34
35        while(lo<=hi){
36            int mid = lo+(hi-lo)/2;
37            if(nums[mid]==target){
38                return mid;
39            }
40            else if(nums[mid] < target){
41                lo = mid+1;
42            }
43            else hi = mid-1;
44        }
45        lo = x;
46        hi = n-1;
47        while(lo<=hi){
48            int mid = lo+(hi-lo)/2;
49            if(nums[mid]==target){
50                return mid;
51            }
52            else if(nums[mid] < target){
53                lo = mid+1;
54            }
55            else hi = mid-1;
56        }
57        return -1;
58    }
59};