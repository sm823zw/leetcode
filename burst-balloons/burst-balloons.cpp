class Solution {
public:
    
    int dp[505][505];
    
    int func(vector<int>&nums, int l, int r, int n){
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int ans = 0;
        for(int i=l+1;i<r;i++){
            int s = func(nums, l, i, n) + func(nums, i, r, n);
            if(l == 0 && r == n){
                s += 1*nums[i]*1;
            }
            else{
                s += nums[l]*nums[i]*nums[r];
            }
            ans = max(ans, s);
        }
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        return func(nums, 0, nums.size()-1, nums.size()-1);
    }
};
