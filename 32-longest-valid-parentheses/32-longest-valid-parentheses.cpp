class Solution {
public:
    int longestValidParentheses(string str){
        stack<int>s;
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                s.push(i);
            }
            else{
                if(!s.empty()){
                    if(str[s.top()] == '('){
                        s.pop();
                    }
                    else{
                        s.push(i);
                    }
                }
                else{
                    s.push(i);
                }
            }
        }
        if(s.empty()){
            return str.size();
        }
        int ans = 0;
        int a = str.size();
        int b = 0;
        while(!s.empty()){
            b = s.top();
            s.pop();
            ans = max(ans, a-b-1);
            a = b;
        }
        return max(ans, a);
    }
};
