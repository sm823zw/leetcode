class Solution {
public:
    
    int ans = 0;
    
    int func(vector<vector<char>>& matrix, int m, int n){
        if(m == 0 || n == 0){
            return matrix[m][n] - '0';
        }
        int a = func(matrix, m, n-1);
        int b = func(matrix, m-1, n);
        int c = func(matrix, m-1, n-1);
        int d = 0;
        if(matrix[m][n] == '1'){
            d++;
        }
        d += min(a, min(b, c));
        ans = max(ans, d);
        return d;
    }
    
    int maximalSquare(vector<vector<char>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==0){
            return 0;
        }
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(matrix[i-1][j-1] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};