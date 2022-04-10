class Solution {
public:
    
    int flag = 0;
    
    void dfs(vector<vector<int>>& graph, int src, int par, vector<int>&vis, int col){
        vis[src] = col;
        for(int i=0;i<graph[src].size();i++){
            if(vis[graph[src][i]] == -1){
                dfs(graph, graph[src][i], src, vis, 1-col);
            }
            else if(graph[src][i] != par && col == vis[graph[src][i]]){
                flag = 1;
                break;
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int>vis(n, -1);
        flag = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == -1){
                dfs(graph, i, 0, vis, 1);
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
