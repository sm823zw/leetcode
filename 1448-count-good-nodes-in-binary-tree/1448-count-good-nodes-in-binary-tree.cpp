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
    int ans=0;
    void dfs(TreeNode *root, int x){
        if(root==NULL){
            return;
        }
        if(root->val>=x){
            ans++;
            x = root->val;
        }
        dfs(root->left, x);
        dfs(root->right, x);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return ans;
    }
};