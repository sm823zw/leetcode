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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(!root){
            return v;
        }
        TreeNode* curr = root;
        queue<TreeNode*>q;
        q.push(curr);
        while(!q.empty()){
            int k = q.size();
            while(k--){
                TreeNode* t = q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                if(k == 0){
                    v.push_back(t->val);
                }
            }
        }
        return v;
    }
};
