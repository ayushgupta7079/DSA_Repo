1class Solution {
2public:
3    struct TreeNode{
4        TreeNode* child[2];
5        int count;
6        TreeNode(){
7            child[1] = child[0] = NULL;
8            count = 0;
9        }
10    };
11
12    void insertion(int num, TreeNode* root){
13
14        TreeNode* node = root;
15
16        for(int i=31;i>=0;i--){
17            int bit = (num >> i)&1;
18
19            if(!node->child[bit]){
20                node->child[bit] = new TreeNode();
21            }
22
23            node = node->child[bit];
24            node->count++;
25        }
26    }
27    void deletion(int num, TreeNode* root){
28
29        TreeNode* node = root;
30
31        for(int i=31;i>=0;i--){
32            int bit = (num >> i)&1;
33            node = node->child[bit];
34            node->count--;
35        }
36    }
37
38    int query(int num, TreeNode* root){
39
40        TreeNode* node = root;
41        int ans = 0;
42
43        for(int i=31;i>=0;i--){
44            int bit = (num >> i)&1;
45            int opp = 1 - bit;
46
47            if(node->child[opp] && (node->child[opp])->count){
48                ans |= (1<<i);
49                node = node->child[opp];
50            }
51            else if((node->child[bit])->count){
52                node = node->child[bit];
53            }
54            else break;
55        }
56        return ans;
57    }
58    int maximumStrongPairXor(vector<int>& nums) {
59        sort(nums.begin(), nums.end());
60        int ans = 0;
61        int n = nums.size();
62        int tail = 0;
63
64        TreeNode* root = new TreeNode();
65        insertion(nums[0], root);
66
67        for(int i=1;i<n;i++){
68            int mini = nums[tail];
69            int cur = nums[i];
70            
71            if(cur <= 2*mini){
72                ans = max(ans, query(cur, root));
73            }
74            else{
75                while(cur > 2*mini){
76                    deletion(mini, root);
77                    tail++;
78                    mini = nums[tail];
79                }
80                ans = max(ans, query(cur, root));
81            }
82
83            insertion(cur, root);
84        }
85
86        return ans;
87    }
88};