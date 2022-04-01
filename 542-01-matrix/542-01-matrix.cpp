class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>ans(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int k = q.size();
            while(k--){
                pair<int, int>p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for(int k=0;k<4;k++){
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if(ii>=0 && ii<m && jj>=0 && jj<n && ans[ii][jj]==-1){
                        q.push({ii, jj});
                        ans[ii][jj] = 1 + ans[i][j];
                    }
                }
            }
        }
        return ans;
    }
};