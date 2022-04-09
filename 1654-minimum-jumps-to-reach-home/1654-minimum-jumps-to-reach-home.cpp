class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x){
        set<pair<int, int>>st;
        int maxx = x + a + b;
        for(int i=0;i<forbidden.size();i++){
            st.insert({forbidden[i], 0});
            st.insert({forbidden[i], 1});
            maxx = max(maxx, a + b + forbidden[i]);
        }
        queue<pair<int,int>>q;
        q.push({0, 0});
        st.insert({0, 0});
        st.insert({0, 1});
        int ans = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                pair<int, int>pos = q.front();
                q.pop();
                if(pos.first == x){
                    return ans;
                }
                if(pos.first-b<= maxx && st.find({pos.first+a, 0})==st.end()){
                    q.push({pos.first+a, 0});
                    st.insert({pos.first+a, 0});
                }
                if(pos.second == 0 && pos.first-b>=0 && st.find({pos.first-b, 1})==st.end()){
                    q.push({pos.first-b, 1});
                    st.insert({pos.first-b, 1});
                }
            }
            ans++;
        }
        return -1;
    }
};