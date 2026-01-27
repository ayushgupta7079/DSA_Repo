1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        
5        int n = arr.size();
6        int sum = 0;
7
8        int ans = 0;
9        for(int head=0; head<n; head++){
10            sum += arr[head];
11
12            if(head >= k){
13                sum -= arr[head-k];
14            }
15
16            if(head >= k-1){
17                int avg = sum/k;
18                if(avg >= threshold) ans += 1;
19            }
20        }
21        return ans;
22    }
23};