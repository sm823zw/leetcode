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
    
    int subtreeSum(TreeNode* root, unordered_map<int, int>&m){
        if(!root){
            return 0;
        }
        int left = subtreeSum(root->left, m);
        int right = subtreeSum(root->right, m);
        root->val += left + right;
        m[root->val]++;
        return root->val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>v;
        if(!root){
            return v;
        }
        unordered_map<int, int>m;
        subtreeSum(root, m);
        int freq = 0;
        for(auto i=m.begin();i!=m.end();i++){
            if(freq < i->second){
                freq = i->second;
            }
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(freq == i->second){
                v.push_back(i->first);
            }
        }
        return v;
    }
};
