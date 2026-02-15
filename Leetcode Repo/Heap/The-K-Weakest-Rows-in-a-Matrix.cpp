1class Solution {
2public:
3    int find(vector<int>& arr){
4        int n = arr.size();
5        int lo = 0 ;
6        int hi = n -1;
7        int ans = n;
8        while(lo <= hi){
9            int mid = lo + (hi - lo)/2;
10            if(arr[mid] == 0){
11                ans = mid;
12                hi = mid-1;
13            }
14            else{
15                lo = mid+1;
16            }
17        }
18        return ans;
19    }
20    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
21        
22        int n = mat.size();
23        int m = mat[0].size();
24
25        vector<int> arr(n);
26
27        for(int i= 0 ;i < n ; i++){
28            arr[i] = find(mat[i]);
29        }
30
31        priority_queue<pair<int,int>> pq;
32        for(int i=0;i<n;i++){
33            pq.push({-arr[i],-i});
34        }
35
36        vector<int>ans(k);
37        int i = 0;
38        while(i!=k){
39            ans[i] = -pq.top().second ;
40            cout<<ans[i]<<endl;
41            pq.pop();
42            i++;
43        }
44        return ans;
45    }
46};