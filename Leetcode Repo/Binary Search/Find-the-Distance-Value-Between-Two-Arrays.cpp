1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        
5        int n = arr1.size();
6        int m = arr2.size();
7
8        int dist = 0;
9        for(int i=0;i<n;i++){
10            bool flag = true;
11            for(int j=0;j<m;j++){
12                if(abs(arr1[i] - arr2[j]) <= d){
13                    flag = false;
14                    break;
15                }
16            }
17            dist += flag;
18        }
19        return dist;
20    }
21};