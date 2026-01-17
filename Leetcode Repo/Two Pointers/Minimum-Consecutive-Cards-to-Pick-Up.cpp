1class Solution {
2public:
3    int minimumCardPickup(vector<int>& cards) {
4        
5        int n = cards.size();
6        int head = -1, tail = 0, ans = 1e9;
7        unordered_map<int,bool> mp;
8
9        while(tail < n){
10
11            while(head + 1 < n && mp[cards[head+1]]==0){
12                head++;
13                mp[cards[head]]=1;
14            }
15
16            if(head+1< n && mp[cards[head]]==1){
17                ans = min(ans, head-tail+2);
18            }
19
20            if(tail > head){
21                tail++;
22                head=tail-1;
23            }
24            else{
25                mp[cards[tail]]=0;
26                tail++;
27            }
28        }
29
30        return ans==1e9?-1:ans;
31    }
32};