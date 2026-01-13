1/** 
2 * Forward declaration of guess API.
3 * @param  num   your guess
4 * @return 	     -1 if num is higher than the picked number
5 *			      1 if num is lower than the picked number
6 *               otherwise return 0
7 * int guess(int num);
8 */
9
10class Solution {
11public:
12    int guessNumber(int n) {
13
14        int lo = 1;
15        int hi = n;
16        while(lo <= hi){
17            int mid = lo + (hi-lo)/2;
18            int x = guess(mid);
19
20            if(!x) return mid;
21            else if(x==1){
22                lo = mid+1;
23            }
24            else hi = mid-1;
25        }
26        return 1;
27    }
28};