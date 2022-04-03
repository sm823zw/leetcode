class Solution {
public:
    
    int end;
    vector<vector<int>>ans;
    vector<int>tmp;
    
    void dfs(vector<vector<int>>& graph, int curr){
        tmp.push_back(curr);
        if(curr == end){
            ans.push_back(tmp);
        }
        else{
            for(int i=0;i<graph[curr].size();i++){
                dfs(graph, graph[curr][i]);
            }
        }
        tmp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        end = graph.size() - 1;
        dfs(graph, 0);
        return ans;
    }
};
