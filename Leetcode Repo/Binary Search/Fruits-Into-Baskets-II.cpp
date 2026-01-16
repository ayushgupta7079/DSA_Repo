1class Solution {
2public:
3    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
4
5        int ans = 0;
6        int n = fruits.size();
7        vector<int> fill(n,0);
8
9        for(int i=0;i<n;i++){
10            for(int j=0;j<n;j++){
11                if(baskets[j] >= fruits[i] && fill[j]==0){
12                    ans++;
13                    fill[j]=1;
14                    break;
15                }
16            }
17        }
18        
19        return n-ans;
20    }
21};