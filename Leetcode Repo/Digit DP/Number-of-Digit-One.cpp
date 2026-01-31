1class Solution {
2public:
3    long long dp[10][2][2]; // [level][tight][0=num,1=ones]
4    string R;
5    int len;
6
7    pair<long long,long long> rec(int level, int tight) {
8        if (level == len) return {1, 0};
9
10        if (dp[level][tight][0] != -1)
11            return {dp[level][tight][0], dp[level][tight][1]};
12
13        int hi = tight ? R[level] - '0' : 9;
14
15        long long totalNum = 0, totalOne = 0;
16
17        for (int i = 0; i <= hi; i++) {
18            int ntight = (tight && i == hi);
19            auto child = rec(level + 1, ntight);
20
21            totalNum += child.first;
22            totalOne += child.second;
23
24            if (i == 1)
25                totalOne += child.first;
26        }
27
28        dp[level][tight][0] = totalNum;
29        dp[level][tight][1] = totalOne;
30        return {totalNum, totalOne};
31    }
32
33    int countDigitOne(int n) {
34        R = to_string(n);
35        len = R.size();
36        memset(dp, -1, sizeof(dp));
37        return rec(0, 1).second;
38    }
39};
40