/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*, int>m;
    int rob(TreeNode* root){
        if(!root){
            return 0;
        }
        if(m.find(root)!=m.end()){
            return m[root];
        }
        // Robs the root
        int ans1 = root->val;
        if(root->left){
            ans1 += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            ans1 += rob(root->right->left) + rob(root->right->right);
        }
        // Doesn't rob the root
        int ans2 = rob(root->left) + rob(root->right);
        m[root] = max(ans1, ans2);
        return m[root];
    }
};
