class Solution {
public:
    
    int bfs(vector<vector<int>>& routes, unordered_map<int, vector<int>>&mp, int source, int target){
        if(source == target){
            return 0;
        }
        unordered_map<int, bool>vis_stops;
        for(auto i=mp.begin();i!=mp.end();i++){
            vis_stops[i->first] = false;
        }
        vector<bool>vis_bus(routes.size(), false);
        queue<pair<int, int>>q;
        q.push({source, 0});
        vis_stops[source] = true;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int curr_stop = t.first;
            int curr_cnt = t.second;
            if(curr_stop == target){
                return curr_cnt;
            }
            vector<int>options = mp[curr_stop];
            for(int i=0;i<options.size();i++){
                int curr_bus = options[i];
                if(!vis_bus[curr_bus]){
                    vector<int>curr_route = routes[curr_bus];
                    for(int j=0;j<curr_route.size();j++){
                        if(!vis_stops[curr_route[j]]){
                            q.push({curr_route[j], curr_cnt+1});
                            vis_stops[curr_route[j]] = true;
                        }
                    }
                    vis_bus[curr_bus] = true;
                }
            }
        }
        return -1;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
        if(source == target || routes.size() == 0){
            return 0;
        }
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        return bfs(routes, mp, source, target);
    }
};