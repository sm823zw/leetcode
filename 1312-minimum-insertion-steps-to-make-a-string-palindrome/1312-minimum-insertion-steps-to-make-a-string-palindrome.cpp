class Solution { 
    public: 
    int lcs(string s1, string s2, int m, int n){ 
        if(m == 0 || n == 0){ 
            return 0;
        } 
        if(s1[m-1] == s2[n-1]){ 
            return 1 + lcs(s1, s2, m-1, n-1); 
        } 
        return max(lcs(s1, s2, m, n-1), lcs(s1, s2, m-1, n)); 
    } 
    
    int minInsertions(string s){ 
        string s1 = s; 
        reverse(s1.begin(), s1.end()); 
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(i!=0 && j!=0){
                    if(s[i-1] == s1[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
                }
            }
        }
        return n - dp[n][n];
    }
};
