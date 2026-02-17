1class Solution {
2public:
3    int countDistinct(vector<int>& nums, int k, int p) {
4        
5
6        int n = nums.size();
7        unordered_set<unsigned long long> st;
8        const unsigned long long base = 1315423911ULL;
9
10        for(int i=0;i<n;i++){
11            int count = 0;
12            unsigned long long hash = 0;
13            for(int j=i;j<n;j++){
14                count += (nums[j] % p == 0);
15                if(count <= k){
16                    hash = hash*base + nums[j];
17                    st.insert(hash);
18                }
19                else break;
20            }
21        }
22
23        return st.size();
24    }
25};