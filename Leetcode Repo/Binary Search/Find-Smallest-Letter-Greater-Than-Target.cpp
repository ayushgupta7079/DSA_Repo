1class Solution {
2public:
3    bool check(int x, int target){
4        return x > target;
5    }
6    char nextGreatestLetter(vector<char>& letters, char target) {
7        
8        int n = letters.size();
9        int lo = 0;
10        int hi = n-1;
11        int ans = n;
12
13        while(lo <= hi){
14            int mid = lo + (hi-lo)/2;
15            int ch = letters[mid] - 'a';
16
17            if(check(ch,target- 'a')){
18                ans = mid;
19                hi = mid-1;
20            }
21            else{
22                lo = mid+1;
23            }
24        }
25        return ans != n ? letters[ans] : letters[0];
26    }
27};