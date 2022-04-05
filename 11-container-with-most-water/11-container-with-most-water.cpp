class Solution {
public:
    int maxArea(vector<int>& height){
        int ans = 0;
        int i = 0;
        int j = height.size()-1;
        while(i<j){
            int m = min(height[i], height[j]);
            ans = max(ans, (j-i)*m);
            while(m >= height[i] && i<j){
                i++;
            }
            while(m >= height[j] && i<j){
                j--;
            }
        }
        return ans;
    }
};