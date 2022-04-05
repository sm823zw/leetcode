class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, int i, unordered_set<int>&vis, unordered_set<int>&cyc, unordered_set<int>&safe){
        // Check if the node is already a part of a cycle.
        if(cyc.find(i) != cyc.end()){
            return false;
        }
        // Check if the node is already marked safe.
        if(safe.find(i) != safe.end()){
            return true;
        }
        // Check if the node is already visited. If yes, then it's a part of a cycle.
        if(vis.find(i) != vis.end()){
            cyc.insert(i);
            return false;
        }
        // Mark the node visited.
        vis.insert(i);
        for(int j=0;j<graph[i].size();j++){
            // Check the adjacent nodes whether or not they are safe.
            if(!dfs(graph, graph[i][j], vis, cyc, safe)){
                // If not safe, then its a part of cycle and hence, so its parent (original node).
                cyc.insert(i);
                return false;
            }
        }
        // Node is safe.
        safe.insert(i);
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n = graph.size();
        unordered_set<int>vis;
        unordered_set<int>cyc;
        unordered_set<int>safe;
        vector<int>ans;
        for(int i=0;i<graph.size();i++){
            if(dfs(graph, i, vis, cyc, safe)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
