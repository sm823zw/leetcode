class Solution {
public:
    
    int m, n;
    
    int func(int i, int j, vector<vector<int>>& pre){
        if(i<0 || j<0){
            return 0;
        }
        if(i>=m){
            i = m-1;
        }
        if(j>=n){
            j = n-1;
        }
        return pre[i][j];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k){
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>>pre(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pre[i][j] = mat[i][j] + func(i, j-1, pre) + func(i-1, j, pre) - func(i-1, j-1, pre);
            }
        }
        vector<vector<int>>ans(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = func(i+k, j+k, pre) - func(i+k, j-1-k, pre) - func(i-1-k, j+k, pre) + func(i-1-k, j-k-1, pre);
            }
        }
        return ans;
    }
};