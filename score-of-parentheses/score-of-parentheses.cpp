class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<string>s;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                s.push("(");
            }
            else{
                int add = 0;
                while(s.top()!="("){
                    add += stoi(s.top());
                    s.pop();
                }
                if(add == 0){
                    add = 1;
                }
                else{
                    add = 2*add;
                }
                s.pop();
                s.push(to_string(add));
            }
        }
        int ans = 0;
        while(!s.empty()){
            ans += stoi(s.top());
            s.pop();
        }
        return ans;
    }
};
