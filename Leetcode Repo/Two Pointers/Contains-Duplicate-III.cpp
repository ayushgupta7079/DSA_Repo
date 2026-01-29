1class Solution {
2public:
3    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
4
5        int k = indexDiff;
6        int n = nums.size();
7        set<long long> st;
8
9        for(int head=0; head <n; head++){
10            
11            if(head > k){
12                st.erase(nums[head-k-1]);
13            }
14            
15            // abs(x - nums[head]) <= t ; -t <= |x-nums[head]| <= t ; x >= nums[head]-t and x - num[head] <= t
16
17            auto ind = st.lower_bound(1ll*nums[head]- valueDiff);
18
19            if(ind != st.end() && (*ind - nums[head]) <= valueDiff) return true;
20            st.insert(nums[head]);
21
22        }
23        return false;
24    }
25};