//Author    Seokho Song
//Date      2019-10-01
//URL       https://leetcode.com/problems/permutation-in-string/
//Approach  TwoPointer, Sliding Window, String

class Solution {
public:
    int s1c[256] = {0};
    int s2c[256] = {0};
    int s1l = 0;
    

    bool check()
    {
        bool flag = false;
        for(int i='a';i<='z';i++)
        {
            if(s1c[i]!=s2c[i])
                flag = true;
        }
        return !flag;
    }
    
    bool checkInclusion(string s1, string s2) 
    {
        int left = 0;
        int right = 0;
        
        if(s2.length()<s1.length())
            return false;
        
        for(int i=0;i<s1.length();i++)
        {
            s1c[s1[i]]++;
            s2c[s2[i]]++;
            right++;
        }
        
        
        
        if(check())
            return true;
        
        while(right<s2.length())
        {
  /*        cout<<"case "<<left<<endl;        
            for(int i ='a'; i<='z'; i++)
            {
                cout<<(char)i<<" = " <<s2c[i]<<endl;
            }
*/
            if(s2c[s2[left]]>0)
                s2c[s2[left]]--;
            s2c[s2[right]]++;

            if(check())
                return true;
            left++;
            right++;
        }
        return false;    
    }
};