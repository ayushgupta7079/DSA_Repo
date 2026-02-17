1class Solution {
2public:
3    struct TreeNode{
4        TreeNode* child[2];
5        TreeNode(){
6            child[0]=child[1]=NULL;
7        }
8    };
9
10    void insert(int num, TreeNode* root){
11        TreeNode* node = root;
12
13        for(int i=31;i>=0;i--){
14            int bit = (num>>i)&1;
15
16            if(!node->child[bit]){
17                node->child[bit] = new TreeNode();
18            }
19
20            node = node->child[bit];
21        }
22    }
23
24    long long query(int num, TreeNode* root){
25
26        TreeNode* node = root;
27        long long ans = 0;
28
29        for(int i=31;i>=0;i--){
30            int bit = (num>>i)&1;
31            int opp = 1-bit;
32
33            if(node->child[opp]){
34                ans |= (1ll<<i);
35                node = node->child[opp];
36            }
37            else{
38                node = node->child[bit];
39            }
40        }
41
42        return ans;
43    }
44    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
45        
46        vector<vector<int>> arr;
47        for(auto v : nums){
48            arr.push_back({v, -1, -1});
49        }
50        int i=0;
51        for(auto v : queries){
52            int x = v[0];
53            int m = v[1];
54            arr.push_back({m, x, i});
55            i++;
56        }
57
58        sort(arr.begin(), arr.end());
59
60        TreeNode* root = new TreeNode();
61        int n = arr.size();
62        vector<int> result(queries.size());
63        int in = 0;
64        
65        for(int i=0;i<n;i++){
66            int ind = arr[i][2];
67            if(ind == -1){
68                int num = arr[i][0];
69                insert(num, root);
70                in++;
71            }
72            else{
73                int num = arr[i][1];
74                if(in){
75                    long long ans =  query(num, root);
76                    result[ind] = ans;
77                }
78                else result[ind]=-1;
79            }
80
81        }
82        return result;
83    }
84};