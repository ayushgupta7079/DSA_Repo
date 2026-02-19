1class Solution {
2public:
3    struct Node{
4        Node* child[2];
5        int count = 0;
6        Node(){
7            child[0] = child[1] = NULL;
8            count = 0;
9        }
10    };
11    void insert(int num, Node* root){
12        Node* node = root;
13
14        for(int i=31;i>=0;i--){
15            int bit = (num >> i)&1;
16
17            if(!node->child[bit]){
18                node->child[bit] = new Node();
19            }
20
21            node = node->child[bit];
22            node->count++;
23        }
24        
25    }
26
27    long long query(int num, Node* root, int k){
28
29        int ans = 0;
30        Node* node = root;
31
32        for(int i=31;i>=0 && node;i--){
33            int bit = (num >> i)&1;
34            int kbit = (k >> i)&1;
35            
36            if (kbit == 1) {
37                // if xor bit = 0, we can take whole subtree
38                if (node->child[bit]) {
39                    ans += node->child[bit]->count;
40                }
41                // continue with xor bit = 1 branch
42                node = node->child[bit ^ 1];
43            } else {
44                // must match xor bit = 0
45                node = node->child[bit];
46            }
47        }
48        return ans;
49    }
50    int countPairs(vector<int>& nums, int low, int high) {
51        
52        Node* root1 = new Node();
53        long long ans1 = 0;
54        int n = nums.size();
55        for(int i=0;i<n;i++){
56            ans1 += query(nums[i], root1, high+1);
57            insert(nums[i], root1);
58        }
59        Node* root2 = new Node();
60        long long ans2 = 0;
61        for(int i=0;i<n;i++){
62            ans2 += query(nums[i], root2, low);
63            insert(nums[i], root2);
64        }
65
66        return int(ans1-ans2);
67    }
68};