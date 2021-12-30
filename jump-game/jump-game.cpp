class Solution {
public:
    bool canJump(vector<int>& nums){
        int m = nums.size();
        if(m == 1){
            return true;
        }
        int d = 0;
        for(int i=0;i<m;i++){
            d = max(d, nums[i]);
            if(d == 0 && i!=m-1){
                return false;
            }
            d--;
        }
        return true;
    }
};
