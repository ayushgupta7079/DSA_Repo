1class Solution {
2public:
3    struct Node{
4        Node* child[2];
5        Node(){
6            child[0] = child[1] = NULL;
7        }
8    };
9
10    void insert(int num, Node* root){
11        Node* node = root;
12
13        for(int i=31;i>=0;i--){
14            int bit = (num>>i)&1;
15            if(!node->child[bit]){
16                node->child[bit] = new Node();
17            }
18            node = node->child[bit];
19        }
20    }
21
22    int query(int num, Node* root){
23        Node* node = root;
24        int ans = 0;
25
26        for(int i=31;i>=0;i--){
27            int bit = (num >> i)&1;
28            int opp = 1 - bit;
29
30            if(node->child[opp]){
31                ans |= (1<<i);
32                node = node->child[opp];
33            }
34            else node = node->child[bit];
35        }
36
37        return ans;
38    }
39    int findMaximumXOR(vector<int>& nums) {
40        Node* root = new Node();
41        insert(nums[0], root);
42        int ans = 0;
43        for(int i=1;i<nums.size();i++){
44            ans = max(ans, query(nums[i], root));
45            insert(nums[i], root);
46        }
47        return ans;
48    }
49};