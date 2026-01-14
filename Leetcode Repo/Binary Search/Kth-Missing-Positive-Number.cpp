1
2/*
3class Solution {
4public:
5    bool check(int mid, vector<int>& arr, int k){
6        bool p = binary_search(arr.begin(), arr.end(), mid); 
7        int ind = lower_bound(arr.begin(),arr.end(), mid) - arr.begin();
8
9        int count = mid - ind - p;
10        return count >= k;
11    }
12    int findKthPositive(vector<int>& arr, int k) {
13        
14        int lo = 1;
15        int hi =  2000;
16        int ans = -1;
17
18        while(lo <= hi){
19            int mid = (lo + hi)/2;
20            if(check(mid,arr,k)){
21                ans = mid;
22                hi = mid-1;
23            }
24            else{
25                lo = mid+1;
26            }
27        }
28        return ans;
29    }
30};
31*/
32class Solution {
33public:
34    int findKthPositive(vector<int>& arr, int k) {
35        int lo = 0, hi = arr.size() - 1;
36        
37        while (lo <= hi) {
38            int mid = lo + (hi - lo) / 2;
39            int missing = arr[mid] - (mid + 1);
40            
41            if (missing >= k){
42                hi = mid - 1;
43            }
44            else{
45                lo = mid + 1;
46            }
47                
48        }
49        
50        // lo is the number of elements <= answer
51        return lo + k;
52    }
53};
54