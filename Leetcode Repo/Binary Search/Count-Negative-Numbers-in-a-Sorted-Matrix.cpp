1class Solution {
2public:
3    int search(vector<int>& arr){
4        int n = arr.size();
5        int lo = 0 ;
6        int hi = n-1;
7        int ans = n;
8        while(lo <= hi){
9            int mid = lo + (hi-lo)/2;
10            if(arr[mid] < 0){
11                ans = mid;
12                hi = mid-1;
13            }
14            else{
15                lo = mid+1;
16            }
17        }
18        return n - ans;
19    }
20    int countNegatives(vector<vector<int>>& grid) {
21        int n = grid.size();
22        int ans = 0;
23        for(int i=0;i<n;i++){
24            ans += search(grid[i]);
25        }
26        return ans;
27        /*
28        int n = grid.size();
29        int m = grid[0].size();
30        int r = 0, c = m - 1;
31        int count = 0;
32
33        while (r < n && c >= 0) {
34            if (grid[r][c] < 0) {
35                count += (n - r);
36                c--;  // move left
37            } else {
38                r++;  // move down
39            }
40        }
41        */
42    }
43};