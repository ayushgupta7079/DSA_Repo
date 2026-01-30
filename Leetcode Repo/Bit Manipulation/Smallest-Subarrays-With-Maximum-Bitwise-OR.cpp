1class Solution {
2public:
3    vector<int> smallestSubarrays(vector<int>& nums) {
4        
5
6        int n = nums.size();
7        vector<int> ans(n);
8        vector<int> last(32,-1);
9
10        for(int j=n-1; j>=0 ;j--){
11            for(int i=0; i<32;i++){
12                if(nums[j] & (1ll << i)){
13                    last[i] = j;
14                }
15            }
16
17            int end = j;
18            for(int i=0;i<32;i++){  
19                if(last[i]!=-1){
20                    end = max(end,last[i]);
21                }
22            }
23
24            ans[j] = end-j+1;
25        }
26        return ans;
27    }
28};