class Solution {
public:
    int flag = 0;
    
    void dfs(vector<int>adj[], int src, int par, vector<int>&vis, int col){
        vis[src] = col;
        for(int i=0;i<adj[src].size();i++){
            if(vis[adj[src][i]] == -1){
                dfs(adj, adj[src][i], src, vis, 1-col);
            }
            else if(adj[src][i] != par && col == vis[adj[src][i]]){
                flag = 1;
                break;
            }
        }
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>vis(n+1, -1);
        flag = 0;
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<n+1;i++){
            if(vis[i] == -1){
                dfs(adj, i, 0, vis, 1);
            }
            if(flag == 1){
                return false;
            }
        }
        if(flag == 1){
            return false;
        }
        return true;
    }
};