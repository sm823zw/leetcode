class Solution {
public:
    
    stack<int>st;
    
    bool dfs(vector<int>adj[], int numCourses, vector<bool>&vis, vector<bool>&stackk, int i){
        vis[i] = true;
        stackk[i] = true;
        vector<int>v = adj[i];
        for(int j=0;j<v.size();j++){
            if(!vis[v[j]]){
                if(dfs(adj, numCourses, vis, stackk, v[j])){
                    return true;
                }
            }
            else{
                if(stackk[v[j]]){
                    return true;
                }
            }
        }
        st.push(i);
        stackk[i] = false;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<int>ans;
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool>vis(numCourses, false);
        vector<bool>stackk(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && dfs(adj, numCourses, vis, stackk, i)){
                return ans;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};