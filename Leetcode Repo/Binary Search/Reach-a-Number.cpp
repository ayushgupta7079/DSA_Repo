1class Solution {
2public:
3    int reachNumber(int target) {
4       long long sum = 0;
5       int step =  0;
6       
7
8       while( sum < abs(target) || (sum - abs(target))%2 != 0){
9            step++; 
10            sum += step;
11       }
12       return step;
13    }
14};