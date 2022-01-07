class Solution {
public:
    
    int func(vector<int>&arr, int m, int k, vector<int>&dp){
        int n = arr.size();
        if(m >= n){
            return 0;
        }
        if(dp[m]!=-1){
            return dp[m];
        }
        int max_sum = 0;
        int max_ele = 0;
        for(int i=m;i<min(n, m+k);i++){
            max_ele = max(max_ele, arr[i]);
            max_sum = max(max_sum, max_ele*(i-m+1) + func(arr, i+1, k, dp));
        }
        return dp[m] = max_sum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int m = arr.size();
        vector<int>dp(m+1, -1);
        return func(arr, 0, k, dp);
    }
};