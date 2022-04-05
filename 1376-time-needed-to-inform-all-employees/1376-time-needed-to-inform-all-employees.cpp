class Solution {
public:
    
    int dfs(vector<int>& informTime, vector<vector<int>>&adj, int emp){
        int ans = 0;
        for(int i=0;i<adj[emp].size();i++){
            ans = max(ans, dfs(informTime, adj, adj[emp][i]));
        }
        return informTime[emp] + ans;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(informTime, adj, headID);
    }
};
