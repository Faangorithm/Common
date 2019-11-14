//Author    Seokho Song
//Date      2019-11-14
//URL       https://leetcode.com/problems/broken-calculator/
//Approach  Array DP

class Solution {
    public int brokenCalc(int X, int Y) {

        int count = 0;

        while(X!=Y){
            if(Y%2 == 1){
                Y+=1;
                count++;
            }else{
                if(Y>X){
                    Y/=2;
                    count++;
                }else{
                    count+= X-Y;
                    X = Y;
                }
            }
        }
        return count;
    }
}