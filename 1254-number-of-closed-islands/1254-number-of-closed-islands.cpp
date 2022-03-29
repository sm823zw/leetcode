class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    
    void dfs(vector<vector<int>>& grid, int r, int c, int count){
        int m = grid.size();
        int n = grid[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n){
            return;
        }
        if(grid[r][c] < 0 || grid[r][c] == 1){
            return;
        }
        grid[r][c] = -count;
        for(int i=0;i<4;i++){
            dfs(grid, r+dx[i], c+dy[i], count);
        }
    }
    
    
    int closedIsland(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int count = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    dfs(grid, i, j, count);
                    count++;
                }
            }
        }
        count--;
        if(count == 0){
            return 0;
        }
        unordered_set<int>st;
        for(int i=0;i<m;i++){
            if(grid[i][0]<0){
                st.insert(grid[i][0]);
            }
            if(grid[i][n-1]<0){
                st.insert(grid[i][n-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]<0){
                st.insert(grid[0][i]);
            }
            if(grid[m-1][i]<0){
                st.insert(grid[m-1][i]);
            }
        }
        return count - st.size();
    }
};