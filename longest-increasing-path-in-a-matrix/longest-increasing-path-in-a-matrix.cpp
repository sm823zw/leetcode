class Solution {
public:
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(dp[i][j] > 0){
            return dp[i][j];
        }
        int ans = 1;
        if(i+1<m && matrix[i+1][j] > matrix[i][j]){
            ans = max(ans, 1 + dfs(matrix, dp, i+1, j));
        }
        if(i-1>=0 && matrix[i-1][j] > matrix[i][j]){
            ans = max(ans, 1 + dfs(matrix, dp, i-1, j));
        }
        if(j+1<n && matrix[i][j+1] > matrix[i][j]){
            ans = max(ans, 1 + dfs(matrix, dp, i, j+1));
        }
        if(j-1>=0 && matrix[i][j-1] > matrix[i][j]){
            ans = max(ans, 1 + dfs(matrix, dp, i, j-1));
        }
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }
};