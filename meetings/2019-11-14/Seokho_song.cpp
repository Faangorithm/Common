//Author    Yunsoo Jung
//Date      2019-11-14
//URL       https://leetcode.com/problems/broken-calculator/
//Approach  Math

class Solution {
public:
    int brokenCalc(int X, int Y) {
        
    int counter = 0;    
    int a = Y;

    if(X==Y)
        return 0;
        
    while(a>X)
    {
        if(a%2==1)
        {
            counter++;
            a++;
        }  
        counter++;
        a/=2;
    }
    int d = X - a;
    return d + counter; 
  }
};