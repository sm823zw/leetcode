class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k){
        int n = nums.size();        
        unordered_map<int, int>mp;
        mp[0] = -1;
        int s = 0;
        for(int i=0;i<n;i++){
            s += nums[i];
            s %= k;
            if(mp.find(s)!=mp.end()){
                if(i-mp[s]>=2){
                    return true;
                }
            }
            else{
                mp[s] = i;
            }
        }
        return false;
    }
};