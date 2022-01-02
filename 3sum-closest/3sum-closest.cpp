class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        sort(v.begin(), v.end());
        int sum = v[0] + v[1] + v[2];
        for(int i=0;i<v.size()-2;i++){
            int j = i+1;
            int k = v.size()-1;
            while(j<k){
                int s = v[i] + v[j] + v[k];
                if(abs(s - target) < abs(sum - target)){
                    sum = s;
                }
                if(s < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return sum;
    }
};