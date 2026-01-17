1class Solution {
2public:
3    int totalFruit(vector<int>& nums) {
4        
5        int n = nums.size();
6        int head=-1;
7        int tail=0;
8        int distinct=0;
9        unordered_map<int,int> mp;
10        int ans = 0;
11
12        while(tail<n){
13            while(head+1<n && (mp[nums[head+1]] || distinct < 2)){
14                head++;
15                mp[nums[head]]++;
16                if(mp[nums[head]]==1) distinct++;
17            }
18            if(distinct <= 2){
19                ans = max(ans,head-tail+1);
20            }
21
22            if(tail > head){
23                tail++;
24                head=tail-1;
25            }
26            else{
27                mp[nums[tail]]--;
28                if(mp[nums[tail]] == 0) distinct--;
29                tail++;
30            }
31        }
32        return ans;
33    }
34};