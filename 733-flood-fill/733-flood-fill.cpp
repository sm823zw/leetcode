class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int col, int newColor){
        int n = image.size();
        if(sr<0 || sr>=n || sc<0 || sr>=n){
            return;
        }
        if(image[sr][sc] != col){
            return;
        }
        image[sr][sc] = newColor;
        dfs(image, sr+1, sc, col, newColor);
        dfs(image, sr-1, sc, col, newColor);
        dfs(image, sr, sc+1, col, newColor);
        dfs(image, sr, sc-1, col, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(image[sr][sc] == newColor){
            return image;
        }
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
