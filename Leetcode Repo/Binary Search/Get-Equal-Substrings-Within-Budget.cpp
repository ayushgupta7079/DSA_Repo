1class Solution {
2public:
3    bool check(int mid, string &s, string &t, int n, int cost){
4
5        int costW = 0;
6        for(int i=0; i<n; i++){
7            costW += abs((s[i]-'a') - (t[i] - 'a'));
8
9            if(i >= mid-1){
10                if(costW <= cost) return 1;
11
12                int l = i - mid + 1;
13                costW -= abs((s[l]-'a') - (t[l] - 'a'));
14            }
15        }
16
17        return 0;
18    }
19    int equalSubstring(string s, string t, int maxCost) {
20        int n = s.length();
21        int lo = 1 ;
22        int hi = n;
23        int ans = 0;
24        while(lo <= hi){
25            int mid = lo + (hi-lo)/2;
26            if(check(mid, s, t, n, maxCost)){
27                ans = mid;
28                lo = mid+1;
29            }
30            else{
31                hi = mid-1;
32            }
33        }
34
35        return ans;
36    }
37};