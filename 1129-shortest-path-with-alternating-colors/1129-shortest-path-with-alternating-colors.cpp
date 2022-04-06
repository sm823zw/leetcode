class Solution {
public:
     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        unordered_map<int, vector<int>> red, blue; 
        for(int i=0;i<red_edges.size();i++) {
            if(red.find(red_edges[i][0])==red.end()) red[red_edges[i][0]]={};
            red[red_edges[i][0]].push_back(red_edges[i][1]);
        }
        for(int i=0;i<blue_edges.size();i++) {
            if(blue.find(blue_edges[i][0])==blue.end()) blue[blue_edges[i][0]]={};
            blue[blue_edges[i][0]].push_back(blue_edges[i][1]);
        }
        vector<int> res(n, -1);
        res[0]=0;
        queue<vector<int>> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});
        while(!q.empty()) {
            vector<int> cur=q.front(), neig=red[cur[0]];
            q.pop();
            if(cur[1]==0) neig=blue[cur[0]];
            for(int i=0;i<neig.size();i++) {
                if(res[neig[i]]==-1) res[neig[i]]=cur[2]+1;
                q.push({neig[i], 1-cur[1], cur[2]+1});
            }
            if(cur[1]==0) blue.erase(cur[0]);
            else red.erase(cur[0]);
        }
        return res;
    }
};