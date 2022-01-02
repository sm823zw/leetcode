class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v){
        vector<vector<int>>ans;
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            int target = -v[i];
            int front = i+1;
            int back = v.size()-1;
            while(front < back){
                int sum = v[front] + v[back];
                if(sum < target){
                    front++;
                }
                else if(sum > target){
                    back--;
                }
                else{
                    vector<int>x = {v[i], v[front], v[back]};
                    ans.push_back(x);
                    while(front < back && v[front] == x[1]){
                        front++;
                    }
                    while(front < back && v[back] == x[2]){
                        back--;
                    }
                }
            }
            while(i+1 < v.size() && v[i+1]==v[i]){
                i++;
            }
        }
        return ans;
    }
};