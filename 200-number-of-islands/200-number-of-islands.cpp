class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    bool check(vector<vector<char>>&grid, vector<vector<bool>>&vis, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        return i>=0 && i<m && j>=0 && j<n && (grid[i][j]=='1' && !vis[i][j]);
    }
    
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>&vis, int i, int j){
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            if(check(grid, vis, ii, jj)){
                dfs(grid, vis, ii, jj);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis;
        for(int i=0;i<m;i++){
            vector<bool>x;
            for(int j=0;j<n;j++){
                x.push_back(false);
            }
            vis.push_back(x);
        }
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, vis, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
