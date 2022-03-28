class Solution {
public:
    
    void dfs(vector<vector<int>>& land, vector<vector<bool>>& vis, int i, int j, int cnt){
        int m = land.size();
        int n = land[0].size();
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }
        if(vis[i][j]){
            return;
        }
        if(land[i][j] == 0){
            return;
        }
        vis[i][j] = true;
        land[i][j] = cnt;
        dfs(land, vis, i-1, j, cnt);
        dfs(land, vis, i+1, j, cnt);
        dfs(land, vis, i, j-1, cnt);
        dfs(land, vis, i, j+1, cnt);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land){
        int m = land.size();
        int n = land[0].size();
        int cnt = 2;
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j] == 1 && !vis[i][j]){
                    dfs(land, vis, i, j, cnt);
                    cnt++;
                }
            }
        }
        vector<vector<int>>ans(cnt-2, vector<int>(4, 0));
        vector<int>flag(cnt, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j] > 1){
                    if(flag[land[i][j]] == 0){
                        flag[land[i][j]] = 1;
                        ans[land[i][j]-2][0] = i;
                        ans[land[i][j]-2][1] = j;
                        ans[land[i][j]-2][2] = i;
                        ans[land[i][j]-2][3] = j;
                    }
                    if(flag[land[i][j]]  == 1){
                        ans[land[i][j]-2][2] = i;
                        ans[land[i][j]-2][3] = j;
                    }
                }
                
            }
        }
        return ans;
    }
};
