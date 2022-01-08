class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int max_cost = 0;
        int sum_cost = 0;
        int ans = 0;
        int n = colors.size();
        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]){
                ans += sum_cost - max_cost;
                sum_cost = 0;
                max_cost = 0;
            }
            sum_cost += neededTime[i];
            max_cost = max(max_cost, neededTime[i]);
        }
        ans += sum_cost - max_cost;
        return ans;
    }
};