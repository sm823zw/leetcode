class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];
        int count = 0;
        while(count < a.size()){
            if(a[count] == b[count]){
                count++;
            }
            else{
                break;
            }
        }
        if(count == 0){
            return "";
        }
        else{
            return a.substr(0, count);
        }
    }
};