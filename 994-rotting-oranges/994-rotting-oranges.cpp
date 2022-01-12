class Solution {
public:
    
    struct Node{
        int c, i, j;
    };
    
    Node* newNode(int c, int i, int j){
        Node* node = new Node;
        node->c = c;
        node->i = i;
        node->j = j;
        return node;
    }
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int orangesRotting(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<Node*>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push(newNode(0, i, j));
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            int i = curr->i;
            int j = curr->j;
            int c = curr->c;
            ans = max(ans, c);
            for(int k=0;k<4;k++){
                if(i+dx[k]>=0 && i+dx[k]<m && j+dy[k]>=0 && j+dy[k]<n){
                    if(grid[i+dx[k]][j+dy[k]] == 1){
                        q.push(newNode(c+1, i+dx[k], j+dy[k]));
                        grid[i+dx[k]][j+dy[k]] = 2;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
