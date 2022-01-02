class Solution {
public:
    int findLength(vector<int>&a, vector<int>&b) {
        int n1 = a.size();
        int n2 = b.size();
        int dp[n1+1][n2+1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(i != 0 && j != 0){
                    if(a[i-1] == b[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                        ans = max(ans, dp[i][j]);
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
