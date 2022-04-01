class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>>q;
        vector<vector<int>>vis(m, vector<int>(n, -1));
        q.push({0, 0, 0, k});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int i = t[0];
            int j = t[1];
            if(i<0 || i>=m || j<0 || j>=n){
                continue;
            }
            
            if(i == m-1 && j == n-1){
                return t[2];
            }
            if(grid[i][j] == 1){
                if(t[3]>0){
                    t[3]--;
                }
                else{
                    continue;
                }
            }
            if(vis[i][j] != -1 && vis[i][j] >= t[3]){
                continue;
            }
            vis[i][j] = t[3];
            for(int k=0;k<4;k++){
                int ii = i + dx[k];
                int jj = j + dy[k];
                q.push({ii, jj, t[2]+1, t[3]});
            }
        }
        return -1;
    }
};
