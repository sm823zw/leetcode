class Solution {
public:
    
    void func(string s, int open, int close, vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if(open!=0){
            string s1 = s + "(";
            func(s1, open-1, close, ans);
        }
        if(close>open){
            string s2 = s + ")";
            func(s2, open, close-1, ans);
        }
        return;
    }

    vector<string> generateParenthesis(int n){
        vector<string>ans;
        int open = n;
        int close = n;
        string s = "";
        func(s, open, close, ans);
        return ans;
    }
};