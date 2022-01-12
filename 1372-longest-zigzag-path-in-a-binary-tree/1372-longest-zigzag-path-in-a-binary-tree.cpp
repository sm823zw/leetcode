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
    
    int helper(TreeNode* root, int left, int right){
        if(!root){
            return 0;
        }
        int a = max(left, right);
        int b = max(helper(root->left, right+1, 0), helper(root->right, 0, left+1));
        return max(a, b);
    }

    int longestZigZag(TreeNode* root) {
        return helper(root, 0, 0);
    }
    
};