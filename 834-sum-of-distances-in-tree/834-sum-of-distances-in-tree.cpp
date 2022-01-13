class Solution {
public:
    
    vector<vector<int>> adj;
    vector<int> count, ans;
    
    void dfs(int node, int par){
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i] != par){
                dfs(adj[node][i], node);
                count[node] += count[adj[node][i]];
                ans[node] += ans[adj[node][i]] + count[adj[node][i]];
            }
        }
        count[node]++;
    }
    
    void dfs1(int node, int n, int par){
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i] != par){
                ans[adj[node][i]] = ans[node] - count[adj[node][i]] + n - count[adj[node][i]];
                dfs1(adj[node][i], n, node);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        count.resize(n);
        ans.resize(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, -1);
        dfs1(0, n, -1);
        return ans;
    }
};