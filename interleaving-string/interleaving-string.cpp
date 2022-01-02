class Solution {
public:
    
    int dp[102][102][202];
    
    bool func(string s1, string s2, string s3, int m, int n, int p){
        if(dp[m][n][p] != -1){
            return dp[m][n][p];
        }
        if(m == 0 && n == 0){
            if(p == 0){
                return dp[m][n][p] = true;
            }
            return dp[m][n][p] = false;
        }
        if(m == 0){
            if(p == 0){
                return dp[m][n][p] = false;
            }
            if(s2[n-1] == s3[p-1]){
                return dp[m][n][p] = func(s1, s2, s3, m, n-1, p-1);
            }
            return dp[m][n][p] = false;
        }
        if(n == 0){
            if(p == 0){
                return dp[m][n][p] = false;
            }
            if(s1[m-1] == s3[p-1]){
                return dp[m][n][p] = func(s1, s2, s3, m-1, n, p-1);
            }
            return dp[m][n][p] = false;
        }
        if(s1[m-1]==s3[p-1] && s2[n-1]==s3[p-1]){
            return dp[m][n][p] = func(s1, s2, s3, m-1, n, p-1) || func(s1, s2, s3, m, n-1, p-1);
        }
        if(s1[m-1]==s3[p-1]){
            return dp[m][n][p] = func(s1, s2, s3, m-1, n, p-1);
        }
        if(s2[n-1]==s3[p-1]){
            return dp[m][n][p] = func(s1, s2, s3, m, n-1, p-1);
        }
        return dp[m][n][p] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3){
        memset(dp, -1, sizeof(dp));
        int i=s1.size();
        int j=s2.size();
        int k=s3.size();
        if(i+j!=k){
            return false;
        }
        return func(s1, s2, s3, i, j, k);
    }
};
