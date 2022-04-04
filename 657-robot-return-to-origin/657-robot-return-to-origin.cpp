class Solution {
public:
    bool judgeCircle(string moves){
        int i = 0;
        int j = 0;
        for(int e=0;e<moves.size();e++){
            if(moves[e] == 'R'){
                i++;
            }
            else if(moves[e] == 'L'){
                i--;
            }
            else if(moves[e] == 'U'){
                j++;
            }
            else if(moves[e] == 'D'){
                j--;
            }
        }
        if(i == 0 && j == 0){
            return true;
        }
        return false;
    }
};