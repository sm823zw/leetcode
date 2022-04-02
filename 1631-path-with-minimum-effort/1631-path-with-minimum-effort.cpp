class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            pair<int, pair<int,int>> p = pq.top();
            pq.pop();
            int d = p.first;
            int i = p.second.first;
            int j = p.second.second;
            if(i == m-1 && j == n-1){
                return d;
            }
            for(int k=0;k<4;k++){
                int ii = i + dx[k];
                int jj = j + dy[k];
                if(ii>=0 && ii<m && jj>=0 && jj<n){
                    int dd = max(d, abs(heights[ii][jj] - heights[i][j]));
                    if(dd < dis[ii][jj]){
                        dis[ii][jj] = dd;
                        pq.push({dd, {ii, jj}});
                    }
                }
            }
        }
        return 0;
    }
};