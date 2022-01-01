class Solution {
public:
    int lengthOfLIS(vector<int>& v){
        int n = v.size();
        int dp[n];
        dp[0]=1;
        int ans = 1;
        for(int i=1;i<n;i++){
            int maxx = 0;
            for(int j=0;j<i;j++){
                if(v[j]<v[i]){
                    maxx = max(maxx, dp[j]);
                }
            }
            dp[i] = 1 + maxx;
            if(dp[i] > ans){
                ans = dp[i];
            }
        }
        return ans;
    }
};
