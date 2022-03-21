class Solution {
public:
    
    void dfs(vector<vector<int>>&adj, int src, int &cnt, vector<bool>&vis){
        vis[src] = true;
        cnt++;
        for(int i=0;i<adj[src].size();i++){
            if(!vis[adj[src][i]]){
                dfs(adj, adj[src][i], cnt, vis);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            long long x1, y1, r1;
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];
            for(int j=0;j<n;j++){
                if(i != j){
                    long long x2, y2;
                    x2 = bombs[j][0];
                    y2 = bombs[j][1];
                    long long diff_x = abs(x1 - x2);
                    long long diff_y = abs(y1 - y2);
                    if(diff_x*diff_x + diff_y*diff_y <= r1*r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int cnt = 0;
            vector<bool>vis(n, false);
            dfs(adj, i, cnt, vis);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
