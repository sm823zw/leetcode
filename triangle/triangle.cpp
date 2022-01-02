class Solution {
public:
    
    
    int func(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
        if(i == triangle.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = triangle[i][j];
        ans += min(func(triangle, dp, i+1, j), func(triangle, dp, i+1, j+1));
        return dp[i][j] = ans;
    }
    
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        return func(triangle, dp, 0, 0);
    }
};

