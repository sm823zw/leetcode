class Solution {
public:

    int dp[102];
    
    int fun(vector<int>arr, int n){
        if(n == 0){
            return dp[0] = 0;
        }
        if(n == 1){
            return dp[1] = arr[0];
        }
        if(n == 2){
            return dp[n] = max(arr[0], arr[1]);
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int a, b;
        if(dp[n-2] != -1){
            a = arr[n-1] + dp[n-2];
        }
        else{
            a = arr[n-1] + fun(arr, n-2);
        }
        if(dp[n-1] != -1){
            b = dp[n-1];
        }
        else{
            b = fun(arr, n-1);
        }
        return dp[n] = max(a, b);
    }

    int rob(vector<int>& arr){
        int n = arr.size();
        if(n == 1){
            return arr[0];
        }
        memset(dp, -1, sizeof(dp));
        vector<int>a1;
        for(int i=0;i<n-1;i++){
            a1.push_back(arr[i]);
        }
        int x = fun(a1, n-1);
        memset(dp, -1, sizeof(dp));
        vector<int>a2;
        for(int i=1;i<n;i++){
            a2.push_back(arr[i]);
        }
        int y = fun(a2, n-1);
        return max(x, y);
    }
    
};