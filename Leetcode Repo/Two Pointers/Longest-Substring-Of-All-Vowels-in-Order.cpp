1class Solution {
2public:
3
4    int get_pos(char ch){
5        if(ch=='a') return 1;
6        if(ch=='e') return 2;
7        if(ch=='i') return 3;
8        if(ch=='o') return 4;
9        return 5;
10    }
11    int longestBeautifulSubstring(string word) {
12        
13        int n = word.size();
14        int head=-1;
15        int tail=0;
16        int ans = 0;
17        int dist = 0;
18        
19        while(tail < n){
20            while(head+1<n && (get_pos(word[head+1]) == dist || get_pos(word[head+1]) == dist+1)){
21                head++;
22                if(get_pos(word[head]) == dist+1) dist++;
23            }
24            // cout<<tail<<" "<<head<<endl;
25            if(dist == 5)ans = max(ans, head-tail+1);
26
27            if(tail > head){
28                tail++;
29                head = tail-1;
30            }
31            else{
32                tail=head+1;;
33                dist = 0;
34            }
35        }
36        return ans;
37    }
38};