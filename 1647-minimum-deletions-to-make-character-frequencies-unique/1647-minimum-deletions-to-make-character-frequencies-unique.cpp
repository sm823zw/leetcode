class Solution {
public:
    int minDeletions(string s){
        int freq[26] = {0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int ans = 0;
        unordered_set<int>st;
        for(int i=0;i<26;i++){
            int k = freq[i];
            if(k!=0){
                if(st.find(k) == st.end()){
                    st.insert(k);
                }
                else{
                    while(st.find(k)!=st.end()){
                        ans++;
                        k--;
                        if(k==0){
                            break;
                        }
                    }
                    if(k!=0){
                        st.insert(k);
                    }
                }
            }
        }
        return ans;
    }
};
