1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int d;
15    int dfs(TreeNode* node){
16        // leaf node
17        if(node == NULL) return 0;
18
19        int left = left = dfs(node->left);
20        int right = dfs(node->right);
21        d = max(d, left+right);
22        return 1 + max(left, right);
23
24    }
25    int diameterOfBinaryTree(TreeNode* root) {
26        d = 0;
27        dfs(root);
28        return d;
29    }
30};