class Solution {
public:
    
    void dfs(vector<vector<int>>& mat, int src, vector<bool>& vis){
        vis[src] = true;
        for(int i=0;i<mat.size();i++){
            if(i!=src && !vis[i] && mat[src][i] == 1){
                dfs(mat, i, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& mat){
        int n = mat.size();
        vector<bool>vis(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(mat, i, vis);
            }
        }
        return count;
    }
};