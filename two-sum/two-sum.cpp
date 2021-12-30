class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        unordered_map<int, int>m;
        for(int i=0;i<v.size();i++){
            m[v[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(m.find(target - v[i]) != m.end()){
                if(i < m[target - v[i]]){
                    ans.push_back(i);
                    ans.push_back(m[target - v[i]]);
                    return ans;
                }
                else if(i > m[target - v[i]]){
                    ans.push_back(m[target - v[i]]);
                    ans.push_back(i);
                    return ans;
                }
            }
        }
        return ans;
    }
};
