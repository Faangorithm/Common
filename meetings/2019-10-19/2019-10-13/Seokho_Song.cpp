//Author    Seokho Song
//Date      2019-10-13
//URL       https://leetcode.com/problems/magical-string/submissions/
//Approach  string, array, brute force

class Solution
{
public:
    int magicalString(int n)
    {
        vector<int> ans;
        int count = 0;s
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(2);
        int j = 2;

        for (int i = 1; i < n; i++)
        {
            int cop = ans[j++];
            if (cop == 1)
            {
                if (ans.back() == 1)
                {
                    ans.push_back(2);
                }
                else
                {
                    ans.push_back(1);
                }
            }
            else
            {
                if (ans.back() == 1)
                {
                    ans.push_back(2);
                    ans.push_back(2);
                }
                else
                {
                    ans.push_back(1);
                    ans.push_back(1);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            //  cout<<ans[i] << ' ';
            if (ans[i] == 1)
                count++;
        }

        return count;
    }
};
