1class Solution {
2public:
3    int maxConsecutiveAnswersHelper(string s, int k, char ch)
4    {
5        int n = s.size();
6        int head = -1;
7        int tail = 0;
8        int ans = 0;
9        int cnt = 0;
10        while(tail < n){
11            while(head+1 < n && (cnt + (s[head+1] == ch) <= k)){
12                head++;
13                if(s[head]==ch) cnt++;
14            }
15            ans = max(ans, head-tail+1);
16
17            if(tail > head){
18                tail++;
19                head=tail-1;
20            }
21            else{
22                if(s[tail]==ch)cnt--;
23                tail++;
24            }
25        }
26        return ans;
27    }
28    int maxConsecutiveAnswers(string s, int k) {
29
30        return max(maxConsecutiveAnswersHelper(s,k,'F'),maxConsecutiveAnswersHelper(s,k,'T'));
31
32
33    }
34};