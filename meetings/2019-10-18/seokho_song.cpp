//Author    Seokho Song
//Date      2019-10-18
//URL       https://leetcode.com/problems/remove-comments/
//Approach  Automata String Parsing

class Solution {
public:
    int status = 0;     
    int get_status(char c)
    {
        if(status==0 && c == '/')
            return 1;
        if(status==1 && c=='*')
            return 3;
        if(status==1 && c=='/')
            return 2;
        if(status==1)
            return 10;
        if(status==3 && c=='*')
            return 4;
        if(status==4 && c=='*')
            return 4;
        if(status==4 && c=='/')
            return 0;
        else if(status==4)
            return 3;
        return status;
    }

    void new_line()
    {
        if(status==2)
            status = 0;
        if(status==1)
            status = 0;
    }
    
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string temp;
        for(int i=0;i<source.size();i++)
        {
            string s = source[i];
            for(int j=0;j<s.length();j++)
            {
                status = get_status(s[j]);
                // cout<<"(s= "<<status<< " : " <<s[j]<<") ";
                if(status==0 && s[j]!='/')
                    temp.push_back(s[j]);
                if(status==10)
                {
                    temp.push_back('/');
                    temp.push_back(s[j]);
                    status = 0;
                }
            }
            if(status!=3)
            {
                if(status==1)
                    temp.push_back('/');
                if(temp.length()!=0)
                     res.push_back(temp);
                temp.clear();
            }    
            new_line();
        }
        return res;
    }
};