class Solution {
public:
    
    int longestPalindromeSubseq(string s1){
        int n = s1.size();
        string s2 = string(s1.rbegin(), s1.rend());
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(i != 0 && j != 0){
                    if(s1[i-1] == s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
                }
            }
        }
        return dp[n][n];
    }
};