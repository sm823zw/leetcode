class Solution {
public:
    
    int func(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();
        if(r<0 || r>=m || c<0 || c>=n){
            return 0;
        }
        if(matrix[r][c] == 0){
            return 0;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int x = func(matrix, r-1, c-1, dp);
        int y = func(matrix, r-1, c, dp);
        int z = func(matrix, r, c-1, dp);
        return dp[r][c] = 1 + min(x, min(y, z));
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans += func(matrix, i, j, dp);
            }
        }
        return ans;
    }
};
