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
        if(grid[r][c] <= 0){
            return;
        }
        grid[r][c] = -count;
        for(int i=0;i<4;i++){
            dfs(grid, r+dx[i], c+dy[i], count);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int count = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, count);
                    count++;
                }
            }
        }
        if(count == 0){
            return 0;
        }
        int c[count];
        memset(c, 0, sizeof(c));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                c[abs(grid[i][j])]++;
            }
        }
        int ans = 0;
        for(int i=1;i<count;i++){
            ans = max(ans, c[i]);
        }
        return ans;
    }
};
