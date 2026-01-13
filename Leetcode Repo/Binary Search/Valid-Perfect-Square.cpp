1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        
5        int lo = 1;
6        int hi = num;
7
8        while(lo <= hi){
9            int mid = lo + (hi-lo)/2;
10            if(1ll*mid*mid == num) return true;
11            else if(1ll*mid*mid < num) lo = mid+1;
12            else hi = mid-1;
13        }
14        return false;
15    }
16};