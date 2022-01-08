class Solution {
public:
    
    bool checkValidString(string s){
        int cmin = 0;
        int cmax = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                cmin++;
                cmax++;
            }
            else if(s[i] == ')'){
                cmin--;
                cmax--;
            }
            else{
                cmax++;
                cmin--;
            }
            if(cmax<0){
                return false;
            }
            cmin = max(cmin, 0);
        }
        return cmin == 0;
    }
};