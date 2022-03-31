class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int, int>>q;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i+1, j});
                    q.push({i-1, j});
                    q.push({i, j+1});
                    q.push({i, j-1});
                }
            }
        }
        while(!q.empty()){
            int k = q.size();
            ans++;
            while(k--){
                pair<int, int>p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                if(i>=0 && i<n && j>=0 && j<n && grid[i][j] == 0){
                    grid[i][j] = -1;//Visited
                    q.push({i+1, j});
                    q.push({i-1, j});
                    q.push({i, j+1});
                    q.push({i, j-1});
                }
            }
        }
        if(ans == 1){
            return -1;
        }
        return ans-1;
    }
};