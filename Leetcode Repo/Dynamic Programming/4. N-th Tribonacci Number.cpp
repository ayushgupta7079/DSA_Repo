/*
1137. N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=dynamic-programming
*/

class Solution
{
public:
    int tribonacci(int n)
    {

        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int a = 0;
        int b = 1;
        int c = 1;
        for (int i = 3; i <= n; i++)
        {
            int temp = a;
            a = b;
            b = c;
            c = a + b + temp;
        }
        return c;
    }
};