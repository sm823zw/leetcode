class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n = rooms.size();
        vector<bool>vis(n, false);
        queue<int>q;
        vis[0] = true;
        for(auto i:rooms[0]){
            q.push(i);
        }
        while(!q.empty()){
            int r = q.front();
            q.pop();
            if(!vis[r]){
                vis[r] = true;
                for(auto i:rooms[r]){
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};