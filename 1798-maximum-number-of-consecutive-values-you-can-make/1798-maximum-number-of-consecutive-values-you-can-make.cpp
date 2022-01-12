class Solution {
public:
    
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(coins.begin(),coins.end());
        
        int curr_value=0;
        
        for(int i=0;i<coins.size();i++)
            if(coins[i]<=curr_value+1)
                curr_value+=coins[i];
            else
                break;
        
        
        return curr_value+1;
    }
};
