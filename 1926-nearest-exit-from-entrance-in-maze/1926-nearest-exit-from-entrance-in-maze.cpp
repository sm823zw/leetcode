class Solution {
public:
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                pair<int, int>p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                for(int k=0;k<4;k++){
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if(ii>=0 && ii<m && jj>=0 && jj<n && maze[ii][jj] == '.'){
                        if(ii==0 || ii==m-1 || jj==0 || jj==n-1){
                            return ans;
                        }
                        maze[ii][jj] = '+';
                        q.push({ii, jj});
                    }
                }
            }
        }
        return -1;
    }
};