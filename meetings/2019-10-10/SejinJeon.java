/*
 * Author    Sejin Jeon
 * Date      2019-10-10
 * URL       https://leetcode.com/problems/can-make-palindrome-from-substring/submissions/
 * Approach  prefix sum, hash map(array)
 */

class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        List<Boolean> resultList = new ArrayList<>();
        int strLen = s.length();
        int[][] prefixSums = new int[strLen + 1][26];
        for (int i = 1; i <= strLen; i++) {
            for (int j = 0; j < 26; j++) {
                prefixSums[i][j] = prefixSums[i - 1][j];
            }
            prefixSums[i][s.charAt(i - 1) - 'a']++;
        }

        for (int[] query : queries) {
            int numOdds = 0;
            for (int i = 0; i < 26; i++) {
                int freq = prefixSums[query[1] + 1][i] - prefixSums[query[0]][i];
                numOdds += (freq % 2);
            }
            if ((query[1] - query[0] + 1) % 2 == 1) numOdds--;
            if (numOdds / 2 <= query[2]) {
                resultList.add(true);
            } else {
                resultList.add(false);
            }
        }
        return resultList;
    }
}
