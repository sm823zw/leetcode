class Solution {
public:
    
    void func(vector<int>& mat, vector<vector<int>>&ans, vector<int>&temp, int st, int target){
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=st;i<mat.size();i++){
            if(i && mat[i]==mat[i-1] && i>st){
                continue;
            }
            temp.push_back(mat[i]);
            func(mat, ans, temp, i+1, target-mat[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& mat, int target){
        sort(mat.begin(), mat.end());
        vector<vector<int>>ans;
        vector<int>temp;
        func(mat, ans, temp, 0, target);
        return ans;
    }
};