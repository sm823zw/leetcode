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
    
    vector<vector<int>>ans;
    
    void helper(TreeNode* root, int targetSum, int s, vector<int>&v){
        if(!root->left && !root->right){
            if(s == targetSum){
                ans.push_back(v);
            }
            return;
        }
        if(root->left){
            v.push_back(root->left->val);
            helper(root->left, targetSum, s + root->left->val, v);
            v.pop_back();
        }
        if(root->right){
            v.push_back(root->right->val);
            helper(root->right, targetSum, s + root->right->val, v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return ans;
        }
        vector<int>v;
        v.push_back(root->val);
        helper(root, targetSum, root->val, v);
        return ans;
    }
};
