//Author    Seokho Song
//Date      2019-10-10
//URL       https://leetcode.com/problems/can-make-palindrome-from-substring/submissions/
//Approach  Prefix, Array, String

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        int lq = queries.size();
        vector<vector<long long>> prefix = vector<vector<long long>>(100001);
        vector<long long> sums(26);
        
        prefix[0] = vector<long long>(26);
    
        for (int i = 0; i < s.length(); i++)
        {
            sums[s[i] - 'a']++;
            prefix[i + 1] = sums;
        }
        vector<bool> ans;
        for (int i = 0; i < lq; i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int k = queries[i][2];

            vector<int> cs(26);
            fill(cs.begin(), cs.end(), 0);

            for (int i = 0; i < 26; i++)
            {
                cs[i] = prefix[right + 1][i] - prefix[left][i];
            }

            for (int j = 0; j < 26; j++)
                cs[j] %= 2;

            int ck = 0;

            for (int j = 0; j < 26; j++)
                ck += cs[j];

            ck -= ((right - left + 1) % 2);

            ck /= 2;
            if (ck <= k)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};