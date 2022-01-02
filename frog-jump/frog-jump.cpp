class Solution {
public:
    
    map<string, bool>mp;
    
    bool func(vector<int>& stones, int curr, int k){
        string s = "curr";
        s += to_string(curr);
        s += "k";
        s += to_string(k);
        if(mp.find(s)!=mp.end()){
            return mp[s];
        }
        for(int i=curr+1;i<stones.size();i++){
            int diff = stones[i] - stones[curr];
            if(diff < k-1){
                continue;
            }
            else if(diff > k+1){
                return mp[s] = false;
            }
            if(func(stones, i, diff)){
                return mp[s] = true;
            }
        }
        if(curr == stones.size()-1){
            return mp[s] = true;
        }
        return mp[s] = false;
    }
    
    bool canCross(vector<int>& stones){
        mp.clear();
        return func(stones, 0, 0);
    }
};