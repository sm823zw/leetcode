class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++){
            dp[i] += nums[i];
            if(dp[i-1] > 0){
                dp[i] += dp[i-1];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};