1class Solution {
2public:
3    int numRescueBoats(vector<int>& people, int limit) {
4        
5        int n = people.size();
6        sort(people.begin(), people.end());
7
8        int i =0;
9        int j = n-1;
10
11        int ans = 0;
12
13        while(i <= j){
14            int a = people[i];
15            int b = people[j];
16
17            if(a + b <= limit){
18                i++;
19                j--;
20            }
21            else{
22                j--;
23            }
24            ans++;
25        }
26
27        return ans;
28    }
29};