class Solution {
public:
    
    int func(string s, string t, int m, int n){
        if(n == 0){
            return 1;
        }
        if(m == 0){
            return 0;
        }
        if(s[m-1] == t[n-1]){
            return func(s, t, m-1, n-1) + func(s, t, m-1, n);
        }
        return func(s, t, m-1, n);
    }
    
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        unsigned long long int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<m+1;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
