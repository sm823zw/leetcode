class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>&q){
        int n = grid.size();
        if(i<0 || i>=n || j<0 || j>=n){
            return;
        }
        if(grid[i][j] == 1){
            grid[i][j] = 2;
            q.push_back({i, j});
            for(int k=0;k<4;k++){
                dfs(grid, i+dx[k], j+dy[k], q);
            }    
        }
        
    }

    int shortestBridge(vector<vector<int>>& grid){
        int n = grid.size();
        vector<pair<int, int>>q;
        for(int i=0;i<n && q.size()==0;i++){
            for(int j=0;j<n && q.size()==0;j++){
                dfs(grid, i, j, q);
            }
        }
        while(!q.empty()){
            vector<pair<int, int>>q1;
            for(int e=0;e<q.size();e++){
                pair<int, int>p = q[e];
                int i = p.first;
                int j = p.second;
                for(int k=0;k<4;k++){
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if(ii>=0 && ii<n && jj>=0 && jj<n){
                        if(grid[ii][jj] == 1){
                            return grid[i][j]-2;
                        }
                        if(grid[ii][jj] == 0){
                            q1.push_back({ii, jj});
                            grid[ii][jj] = grid[i][j] + 1;
                        }
                    }
                }
            }
            swap(q, q1);
        }
        return 0;
    }
};
