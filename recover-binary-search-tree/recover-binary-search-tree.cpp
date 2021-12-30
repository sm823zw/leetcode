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
    
    TreeNode* a, *b, *x;
    
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        if(x){
            if(!a && x->val > root->val){
                a = x;
            }
            if(a && x->val > root->val){
                b = root;
            }
        }
        x = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root){
        a = NULL;
        b = NULL;
        x = NULL;
        inorder(root);
        int y = a->val;
        a->val = b->val;
        b->val = y;
    }
};