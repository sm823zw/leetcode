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
    
    int helper(TreeNode* root, int s){
        if(!root){
            return s;
        }
        s += root->val;
        if(!root->left && !root->right){
            return s;
        }
        s = s* 10;
        if(!root->left){
            return helper(root->right, s);
        }
        if(!root->right){
            return helper(root->left, s);
        }
        return helper(root->left, s) + helper(root->right, s);
    }
    
    
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        return helper(root, 0);
    }
};