class Solution {
public:

    int minMovesToMakePalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        int ans = 0;
        while(l<r){
            int a = l;
            int b = r;
            while(s[a]!=s[b]){
                b--;
            }
            if(a == b){
                swap(s[b], s[b+1]);
                ans++;
                continue;
            }
            else{
                while(b<r){
                    swap(s[b], s[b+1]);
                    ans++;
                    b++;
                }
            }
            l++;
            r--;
        }
        return ans;
    }
};