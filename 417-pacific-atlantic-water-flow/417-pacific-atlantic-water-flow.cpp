class Solution {
public:
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>&vis, int i, int j, int ht){
        int m = heights.size();
        int n = heights[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }
        if(vis[i][j]){
            return;
        }
        if(heights[i][j]<ht){
            return;
        }
        vis[i][j] = true;
        dfs(heights, vis, i+1, j, heights[i][j]);
        dfs(heights, vis, i-1, j, heights[i][j]);
        dfs(heights, vis, i, j+1, heights[i][j]);
        dfs(heights, vis, i, j-1, heights[i][j]);
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> visitedPacific(m, vector<bool>(n, false));
		vector<vector<bool>> visitedAtlantic(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            dfs(heights, visitedPacific, i, 0, heights[i][0]);
            dfs(heights, visitedAtlantic, i, n-1, heights[i][n-1]);
        }
        for(int j=0;j<n;j++){
            dfs(heights, visitedPacific, 0, j, heights[0][j]);
            dfs(heights, visitedAtlantic, m-1, j, heights[m-1][j]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visitedPacific[i][j] && visitedAtlantic[i][j]){
                    vector<int>x;
                    x.push_back(i);
                    x.push_back(j);
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};