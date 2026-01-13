1class Solution {
2public:
3    int peakIndexInMountainArray(vector<int>& arr) {
4        int n = arr.size();
5        int lo = 0;
6        int hi = n-1;
7        int ans = hi;
8
9        while(lo <= hi){
10            int mid = lo + (hi-lo)/2;
11
12            if(mid!=n-1 && arr[mid] >= arr[mid+1]){
13                ans = mid;
14                hi = mid-1;
15            }
16            else{
17                lo = mid+1;
18            }
19        }
20        return ans;
21    }
22};