class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector<int>cnt(n+1, 0);
        for(int i=0;i<trust.size();i++){
            cnt[trust[i][0]]--;
            cnt[trust[i][1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(cnt[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};