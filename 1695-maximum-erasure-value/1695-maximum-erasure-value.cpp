class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>m;
        int i = 0;
        int j = 0;
        int ans = 0;
        int s = 0;
        while(j < n){
            m[nums[j]]++;
            s += nums[j];
            if(m.size() == j-i+1){
                if(ans < s){
                    ans = s;
                }
                j++;
            }
            else if(m.size() < j-i+1){
                while(m.size() < j-i+1){
                    s -= nums[i];
                    m[nums[i]]--;
                    if(m[nums[i]] == 0){
                        m.erase(nums[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
