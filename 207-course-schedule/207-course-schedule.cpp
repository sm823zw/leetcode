class Solution {
public:
    
    bool dfs(vector<int>adj[], int numCourses, vector<bool>&vis, vector<bool>&stack, int i){
        vis[i] = true;
        stack[i] = true;
        vector<int>v = adj[i];
        for(int j=0;j<v.size();j++){
            if(!vis[v[j]]){
                if(dfs(adj, numCourses, vis, stack, v[j])){
                    return true;
                }
            }
            else{
                if(stack[v[j]]){
                    return true;
                }
            }
        }
        stack[i] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>vis(numCourses, false);
        vector<bool>stack(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && dfs(adj, numCourses, vis, stack, i)){
                return false;
            }
        }
        return true;
    }
};