class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> mat(n, vector<int>(n, 1));
        for(auto mine: mines){
            mat[mine[0]][mine[1]] = 0;
        }
        
        int right, left, up, down;
        
        for(int i=0;i<n;i++){
            right = 0;
            down = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    right++;
                }
                else{
                    right = 0;
                }
                if(mat[j][i] == 1){
                    down++;
                }
                else{
                    down = 0;
                }
                dp[i][j] = min(dp[i][j], right);
                dp[j][i] = min(dp[j][i], down);
            }
        }
        
        for(int i=0;i<n;i++){
            up = 0;
            left = 0;
            for(int j=n-1;j>=0;j--){
                if(mat[i][j] == 1){
                    left++;
                }
                else{
                    left = 0;
                }
                if(mat[j][i] == 1){
                    up++;
                }
                else{
                    up = 0;
                }
                dp[i][j] = min(dp[i][j], left);
                dp[j][i] = min(dp[j][i], up);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};