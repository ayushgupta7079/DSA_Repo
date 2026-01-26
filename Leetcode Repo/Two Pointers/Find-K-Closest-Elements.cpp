1class Solution {
2public:
3    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
4        
5        int n = arr.size();
6        int l =0,r = n-1;
7
8        while((r-l+1) > k){
9            if(abs(arr[l] - x) > abs(arr[r] - x)){
10                l++;
11            }
12            else r--;
13        }
14
15        return vector<int>(arr.begin() + l, arr.begin() + l + k);
16    }
17};