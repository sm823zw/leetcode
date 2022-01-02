class Solution {
public:
    
    bool func(vector<int>& nums, vector<bool>& vis, int st, int k, int curr, int sub){
        if(k == 1){
            return true;
        }
        if(curr > sub){
            return false;
        }
        if(curr == sub){
            return func(nums, vis, 0, k-1, 0, sub);
        }
        for(int i=st;i<nums.size();i++){
            if(!vis[i]){
                vis[i] = true;
                if(func(nums, vis, i+1, k, curr+nums[i], sub)){
                    return true;
                }
                vis[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = 0;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
        }
        if(s % k != 0){
            return false;
        }
        if(nums.size() < k){
            return false;
        }
        vector<bool>vis(nums.size(), false);
        return func(nums, vis, 0, k, 0, s/k);
    }
};
