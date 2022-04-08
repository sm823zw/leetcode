class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank){
        unordered_set<string>st(bank.begin(), bank.end());
        if(st.find(end)==st.end()){
            return -1;
        }
        queue<string>q;
        unordered_set<string>vis;
        q.push(start);
        vis.insert(start);
        int cnt = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                string s = q.front();
                q.pop();
                if(s == end){
                    return cnt;
                }
                for(auto ss : neighbors(s)){
                    if(st.find(ss)!=st.end() && vis.find(ss)==vis.end()){
                        q.push(ss);
                        vis.insert(ss);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
    
    vector<string>neighbors(string &s){
        string options = "ACGT";
        vector<string>ans;
        for(int i=0;i<4;i++){
            for(int j=0;j<s.size();j++){
                string ss = s;
                if(ss[j]!=options[i]){
                    ss[j] = options[i];
                    ans.push_back(ss);
                }
            }
        }
        return ans;
    }
    
};
