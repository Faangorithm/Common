//Author    Yunsoo Jung
//Date      2019-10-19
//URL       Approach  String, BruteForce
//Approach  String
"""

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        int n = source.size();
        vector<string> ans;
        string agg;
        string token;
        bool multiComment = false;
        for(int i = 0; i < n; i ++){
            string source_line = source[i];
            int m = source_line.size();
            int j = 0;
            if(!multiComment){
                agg = "";
            }
            while(j < m){
                token = (j != m -1)? source_line.substr(j, 2) : source_line.substr(j, 1); 
                if(multiComment){
                    if(token.compare("*/") == 0){
                        multiComment = false;
                        j += 2;
                    }
                    else{
                        j += 1;
                    }
                }
                else if(token.compare("//") == 0){
                    break;
                }
                else if(token.compare("/*") == 0){
                    multiComment = true;
                    j += 2;
                }
                else{
                    agg += source_line[j];
                    j += 1;
                }
            }
            if(multiComment){
                continue;
            }
            if(agg.compare("") != 0){
                ans.push_back(agg);
            }
        }
        return ans;
    }
};




