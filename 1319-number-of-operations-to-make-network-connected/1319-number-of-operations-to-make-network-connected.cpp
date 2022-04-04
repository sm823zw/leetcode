class Solution {
public:
    
    void dfs(vector<int>adj[], int n, int i, vector<bool>&vis){
        vis[i] = true;
        for(int j=0;j<adj[i].size();j++){
            if(!vis[adj[i][j]]){
                dfs(adj, n, adj[i][j], vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections){
        int n_conn = connections.size();
        if(n_conn < n-1){
            return -1;
        }
        vector<int>adj[n];
        for(int i=0;i<n_conn;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int cnt = 0;
        vector<bool>vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj, n, i, vis);
                cnt++;
            }
        }
        return cnt-1;
    }
};
