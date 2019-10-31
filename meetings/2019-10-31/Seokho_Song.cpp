//Author    Seokho Song
//Date      2019-10-31
//URL       https://leetcode.com/problems/maximum-swap/
//Approach  Array

class Solution {
public:

    void swap(int* a,int*b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int maximumSwap(int num) {
        int digits[10]={0};
        int maxdigits[10]={0};
        int mv = 0;
        int mi = 0;
        int length = 0;
        while(num)   
        {
            digits[length] = num % 10;
            num/=10;
            length++;
        }
        
        for(int i=0;i<length;i++)
        {
            if(mv < digits[i])
            {
                mi = i;
                mv = digits[i];
            }
            maxdigits[i] = mi;                

        }

        for(int i=length-1;i>=0;i--)
        {
            if(digits[maxdigits[i]] != digits[i])
            {
                swap(&digits[maxdigits[i]], &digits[i]);
                break;
            }
        }
        
        int ans = 0;
        
        for(int i=length-1;i>=0;i--)
        {
            ans*=10;
            ans += digits[i];
        }
        return ans;
        
        
    }
};