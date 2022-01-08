class Solution {
public:
    // Non-repetitive numbers    
    // int firstMissingPositive(vector<int>& nums){
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         if(nums[i]<=0){
    //             nums[i] = INT_MAX;
    //         }
    //     }
    //     nums.push_back(INT_MAX);
    //     for(int i=0;i<n+1;i++){
    //         if(abs(nums[i])<n+1 && abs(nums[i])>0){
    //             nums[abs(nums[i])-1] = - nums[abs(nums[i])-1];
    //         }
    //     }
    //     int ans = 0;
    //     for(int i=0;i<n+1;i++){
    //         if(nums[i]>0){
    //             return i+1;
    //         }
    //     }
    //     return 0;
    // }
    
    // Repetitive numbers
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n){
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        for (i = 0; i < n; i++){
            if (nums[i] != (i+1)){
                return i+1;
            }
        }            
        return n+1;
    }
};