1class Solution {
2public:
3    long long squareSum(int num){
4        long long sum = 0;
5        while(num > 0){
6            long long x = num%10;
7            sum += x*x;
8            num /= 10;
9        }
10        return sum;
11    }
12    bool isHappy(int n) {
13        
14        while(n!=1 && n!=4){
15            n = squareSum(n);
16        }
17
18        return n==1;
19    }
20};