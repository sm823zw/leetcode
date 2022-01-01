class Solution {
public:
    
    int func(vector<int>coins, int s, int m){
        if(s == 0){
            return 1;
        }
        if(m == 0){
            return 0;
        }
        if(s-coins[m-1]>=0){
            return func(coins, s-coins[m-1], m) + func(coins, s, m-1);
        }
        else{
            return func(coins, s, m-1);
        }
    }
    
    
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        int dp[amount+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<amount+1;i++){
            for(int j=0;j<m+1;j++){
                if(i == 0){
                    dp[i][j] = 1;
                }
                else if(j == 0){
                    dp[i][j] = 0;
                }
                else if(i-coins[j-1]>=0){
                    dp[i][j] = dp[i-coins[j-1]][j] + dp[i][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[amount][m];
    }
};
