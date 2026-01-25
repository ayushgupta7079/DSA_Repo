1class Solution {
2public:
3    bool isPowerOfTwo(int n) {
4        
5        return n>0 && __builtin_popcount(n)==1;
6    }
7};