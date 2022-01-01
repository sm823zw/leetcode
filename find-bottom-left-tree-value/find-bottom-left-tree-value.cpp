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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int ans = -1;
        while(!q.empty()){
            int k = q.size();
            int f = 0;
            while(k--){
                TreeNode* t = q.front();
                if(f == 0){
                    ans = t->val;
                    f = 1;
                }
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }   
            }
        }
        return ans;
    }
};
