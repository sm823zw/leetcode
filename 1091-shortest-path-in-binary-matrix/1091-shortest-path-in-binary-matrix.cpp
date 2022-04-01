class Solution {
public:
    
    int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
    int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }
        queue<pair<int, int>>q;
        q.push({0, 0});
        grid[0][0] = -1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                pair<int, int>p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                if(i == n-1 && j == n-1){
                    return ans;
                }
                for(int k=0;k<8;k++){
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if(ii>=0 && ii<n && jj>=0 && jj<n && grid[ii][jj] == 0){
                        q.push({ii, jj});
                        grid[ii][jj] = -1;
                    }
                }
            }
        }
        return -1;
    }
};
