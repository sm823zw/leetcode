class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int n = s.size();
        unordered_map<char, int>m;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<n){
            m[s[j]]++;
            if(m.size() == j-i+1){
                if(ans < m.size()){
                    ans = m.size();
                }
                j++;
            }
            else if(m.size() < j-i+1){
                while(m.size() < j-i+1){
                    m[s[i]]--;
                    if(m[s[i]] == 0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
