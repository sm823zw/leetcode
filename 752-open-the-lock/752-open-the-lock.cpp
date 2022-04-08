class Solution {
public:
    int openLock(vector<string>& deadends, string target){
        unordered_set<string>st(deadends.begin(), deadends.end());
        if(st.find("0000")!=st.end()){
            return -1;
        }
        queue<string>q;
        q.push("0000");
        int cnt = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                string s = q.front();
                q.pop();
                if(s == target){
                    return cnt;
                }
                for(auto i : neighbors(s)){
                    if(st.find(i)==st.end()){
                        st.insert(i);
                        q.push(i);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
    
    vector<string>neighbors(string& s){
        vector<string>ans;
        for(int i=0;i<4;i++){
            string ss = s;
            ss[i] = (ss[i] - '0' - 1 + 10)%10 + '0';
            ans.push_back(ss);
            ss = s;
            ss[i] = (ss[i] - '0' + 1 + 10)%10 + '0';
            ans.push_back(ss);
        }
        return ans;
    }
};
