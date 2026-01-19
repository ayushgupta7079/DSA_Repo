1class Solution {
2public:
3
4    int equalSubstring(string s, string t, int maxCost) {
5        int n = s.length();
6        int head=-1;
7        int tail=0;
8        int ans = 0;
9        int costW = 0;
10
11        while(tail < n){
12            while(head+1<n && (costW + abs( (s[head+1]-'a') - (t[head+1] - 'a') ) <= maxCost )){
13                head++;
14                costW +=  abs( (s[head]-'a') - (t[head] - 'a') );
15            }
16
17            ans = max(ans, head-tail+1);
18
19            if(tail > head){
20                tail++;
21                head=tail-1;
22            }
23            else{
24                costW -= abs( (s[tail]-'a') - (t[tail] - 'a') );
25                tail++;
26            }
27        }
28
29        return ans;
30
31        return ans;
32    }
33};