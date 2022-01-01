class Solution {
public:
    int sz;
    void func(vector<int>&squares, int n, int sum, int pos, int cnt){
        if(pos>=squares.size()){
            return;
        }
        if(cnt>=sz){
            return;
        }
        if(sum>n){
            return;
        }
        if(sum == n){
            sz = min(sz, cnt);
            return;
        }
        func(squares, n, sum, pos+1, cnt);
        func(squares, n, sum+squares[pos], pos, cnt+1);
    }
    
    int numSquares(int n){
        vector<int>squares;
        for(int i=0;i<100,i*i<=n;i++){
            squares.push_back(i*i);
            if(i*i == n){
                return 1;
            }
        }
        sz = n;
        func(squares, n, 0, 0, 0);
        return sz;
    }
};
