1class Solution {
2public:
3    struct TreeNode{
4        TreeNode* child[2];
5        TreeNode(){
6            child[0] = child[1] = NULL;
7        }
8    };
9
10
11    void insert(int num, TreeNode* root){
12
13        TreeNode* node = root;
14
15        for(int i=31;i>=0;i--){
16            int bit = (num >> i) & 1;
17
18            if(!node->child[bit]){
19                node->child[bit] = new TreeNode();
20            }
21            node = node->child[bit];
22        }
23    };
24
25    int query(int num, TreeNode* root){
26        int ans = 0;
27        TreeNode* node = root;
28
29        for(int i=31;i>=0;i--){
30            int bit = (num >> i) & 1;
31            int opp = 1 - bit;
32
33            if(node->child[opp]){
34                ans |= (1<<i);
35                node = node->child[opp];
36            }
37            else{
38                node = node->child[bit];
39            }
40        }
41
42        return ans;
43    }
44    int findMaximumXOR(vector<int>& nums) {
45        int n = nums.size();
46        TreeNode* root = new TreeNode();
47        int ans = 0;
48        for(int i=0;i<n;i++){
49            if(i >= 1){
50                ans = max(ans, query(nums[i], root));
51            }
52            insert(nums[i], root);
53        }
54        return ans;
55    }
56};