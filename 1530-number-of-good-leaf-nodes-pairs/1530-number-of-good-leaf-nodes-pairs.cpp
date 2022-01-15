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
    int ans = 0;
    
    vector<int>dfs(TreeNode* root, int distance){
        if(!root){
            return {};
        }
        if(!root->left && !root->right){
            return {1};
        }
        vector<int>left = dfs(root->left, distance);
        vector<int>right = dfs(root->right, distance);
        for(int i=0;i<left.size();i++){
            for(int j=0;j<right.size();j++){
                if(left[i] + right[j] <= distance){
                    ans++;
                }
            }
        }
        vector<int>v;
        for(int i=0;i<left.size();i++){
            left[i]++;
            v.push_back(left[i]);
        }
        for(int i=0;i<right.size();i++){
            right[i]++;
            v.push_back(right[i]);
        }
        return v;
    }
    
    int countPairs(TreeNode* root, int distance){
        dfs(root, distance);
        return ans;
    }
};