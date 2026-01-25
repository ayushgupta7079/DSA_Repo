1class Solution {
2public:
3    bool isPowerOfFour(int n) {
4        int count = __builtin_popcount(n);
5        // cout<<count<<endl;
6        if(count != 1 || n <0) return 0;
7        
8        for(int i=0;i<32;i++){
9            if((n>>i)&1) return i%2==0;
10        }
11        return 0;
12    }
13};