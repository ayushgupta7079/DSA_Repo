1class Solution {
2public:
3    bool isvo(char ch){
4        ch = tolower(ch);
5       return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ;
6    }
7    int maxVowels(string s, int k) {
8        
9        int n = s.length();
10        int head=-1,tail=0;
11        int v = 0;
12        int cnt = 0;
13        int ans = 0;
14
15        while(tail<n){
16            while(head+1<n && cnt<k){
17                head++;
18                if(isvo(s[head]))v++;
19                cnt++;
20            }
21            if(cnt==k){
22                ans = max(ans,v);
23            }
24            if(tail>head){
25                tail++;
26                head= tail-1;
27            }
28            else{
29                if(isvo(s[tail])) v--;
30                tail++;
31                cnt--;
32            }
33        }
34        return ans;
35    }
36};