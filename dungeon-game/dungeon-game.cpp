class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int dp[m+1][n+1];
        memset(dp, 1e9+5, sizeof(dp));
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ans = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
                if(ans <= 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = ans;
                }
            }
        }
        return dp[0][0];
    }
};
