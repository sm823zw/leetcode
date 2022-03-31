class Solution {
public:
    int numSubseq(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int ans = 0;
        int mod = 1e9+7;
        vector<int>pows(nums.size(), 1);
        for(int k=1;k<nums.size();k++){
            pows[k] = (pows[k-1]*2) % mod;
        }
        while(i<=j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                ans = (ans + pows[j-i])%mod;
                i++;
            }
        }
        return ans%mod;
    }
};