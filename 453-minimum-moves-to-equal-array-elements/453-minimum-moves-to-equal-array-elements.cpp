class Solution {
public:
    int minMoves(vector<int>& nums) {
        int s = 0;
        int m = INT_MAX;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            m = min(m, nums[i]);
        }
        return s - nums.size()*m;
    }
};
