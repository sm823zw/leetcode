class Solution {
public:
    
    string code[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void func(string digits, int st, string s, vector<string>&ans){
        if(st == digits.size()){
            ans.push_back(s);
            return;
        }
        string option = code[digits[st]-'0'];
        for(int i=0;i<option.size();i++){
            string s1 = s + option[i];
            func(digits, st+1, s1, ans);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits){
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string s = "";
        func(digits, 0, s, ans);
        return ans;
    }
};
