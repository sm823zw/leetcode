/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t->left){
                q.push(t->left);
                parent[t->left] = t;
            }
            if(t->right){
                q.push(t->right);
                parent[t->right] = t;
            }
        }
        q.push(target);
        vis[target] = true;
        int curr_lev = 0;
        while(!q.empty()){
            if(curr_lev == k){
                break;
            }
            curr_lev++;
            int sz = q.size();
            while(sz--){
                TreeNode* t = q.front();
                q.pop();
                if(t->left && !vis[t->left]){
                    q.push(t->left);
                    vis[t->left] = true;
                }
                if(t->right && !vis[t->right]){
                    q.push(t->right);
                    vis[t->right] = true;
                }
                if(parent[t] && !vis[parent[t]]){
                    q.push(parent[t]);
                    vis[parent[t]] = true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};