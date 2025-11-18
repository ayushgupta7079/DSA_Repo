/*
509. Fibonacci Number
https://leetcode.com/problems/fibonacci-number/description/?source=submission-noac
*/

class Solution
{
public:
  int fib(int n)
  {
    if (n <= 1)
      return n;
    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
      int temp = a;
      a = b;
      b = temp + b;
    }
    return b;
  }
};