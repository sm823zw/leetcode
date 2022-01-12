class Solution {
public:
    int countServers(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int row[m];
        int col[n];
        int total = 0;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
                total += grid[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    if(row[i] == 1 && col[j] == 1){
                        ans++;
                    }
                }
            }
        }
        return total - ans;
    }
};
