//Author    Seokho Song
//Date      2019-10-10
//URL       https://leetcode.com/problems/can-make-palindrome-from-substring/submissions/
//Approach  Heuristic, String, Array

class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        int lq = queries.size();
        const int PSIZE = 1000;
        const int HSIZE = 10000;
        vector<vector<int>> bigH(101);
        fill(bigH.begin(), bigH.end(), vector<int>(26));
        vector<vector<int>> heuristic(1001);
        for (int i = 0; i < 1000; i++)
            heuristic[i] = vector<int>(26);

        for (int i = 0; i < s.length(); i++)
        {
            bigH[i / HSIZE][s[i] - 'a']++;
            heuristic[i / PSIZE][s[i] - 'a']++;
        }
        vector<bool> ans;
        for (int i = 0; i < lq; i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int k = queries[i][2];

            vector<int> cs(26);
            fill(cs.begin(), cs.end(), 0);

            for (int j = left; j <= right; j++)
            {

                if (j % HSIZE == 0 && j + HSIZE <= right)
                {
                    for (int p = 0; p < 26; p++)
                        cs[p] += bigH[j / HSIZE][p];
                    j += HSIZE - 1;
                }
                else if (j % PSIZE == 0 && j + PSIZE <= right)
                {
                    for (int p = 0; p < 26; p++)
                        cs[p] += heuristic[j / PSIZE][p];
                    j += PSIZE - 1;
                }
                else
                    cs[s[j] - 'a']++;
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