class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2){
        int m = s1.size();
        int n = s2.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                if(i != 0 && j != 0){
                    if(s1[i-1] == s2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
                }
            }
        }
        string scs = "";
        int i = m;
        int j = n;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                scs += s1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    scs += s2[j-1];
                    j--;
                }
                else{
                    scs += s1[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            scs += s1[i-1];
            i--;
        }
        while(j>0){
            scs += s2[j-1];
            j--;
        }
        string ans = string(scs.rbegin(), scs.rend());
        return ans;
    }
};