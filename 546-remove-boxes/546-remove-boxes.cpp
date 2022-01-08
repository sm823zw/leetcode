class Solution {
public:
    
    int dp[200][200][200];
    
    int dfs(vector<int>&boxes, int l, int r, int k){
        if(l>r){
            return 0;
        }
        if(dp[l][r][k]>0){
            return dp[l][r][k];
        }
        int ll = l;
        int kk = k;
        while(l<r && boxes[l] == boxes[l+1]){
            l++;
            k++;
        }
        int ans = (k+1)*(k+1) + dfs(boxes, l+1, r, 0);
        for(int i=l+1;i<r+1;i++){
            if(boxes[i] == boxes[l]){
                ans = max(ans, dfs(boxes, l+1, i-1, 0) + dfs(boxes, i, r, k+1));
            }
        }
        return dp[ll][r][kk] = ans;
    }
    
    int removeBoxes(vector<int>&boxes){
        memset(dp, 0, sizeof(dp));
        return dfs(boxes, 0, boxes.size()-1, 0);
    }
};