class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr){
        int n = arr.size();
        int ans = 0;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i=2;i<n;i++){
            int l = 0;
            int r = i-1;
            while(l<r){
                int s = arr[l] + arr[r];
                if(s > arr[i]){
                    r--;
                }
                else if(s < arr[i]){
                    l++;
                }
                else{
                    dp[r][i] = dp[l][r] + 1;
                    ans = max(ans, dp[r][i]);
                    r--;
                    l++;
                }
            }
        }
        if(ans == 0){
            return ans;
        }
        return ans + 2;
    }
};