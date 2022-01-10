class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<long long, vector<long long>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<long long> ans;
        vector<long long> pre(arr.size(), 0), suf(arr.size(), 0);
        for(auto m : mp){
            vector<long long> v = m.second;
            for(int i = 1;i<v.size();i++){
                pre[v[i]] = pre[v[i-1]] + i * (v[i] - v[i-1]); 
            }
        }
        for(auto m : mp){
            vector<long long> v = m.second;
            for(int i= v.size()-2;i>=0;i--){
                suf[v[i]] = suf[v[i+1]] + (v.size()-1-i) * (v[i+1] - v[i]);
            }
        }
        for(int i=0;i<pre.size();i++){
            ans.push_back(pre[i] + suf[i]);
        }
        return ans;
    }
};
