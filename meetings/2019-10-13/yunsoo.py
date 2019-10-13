"""
Author    Yunsoo Jung
Date      2019-10-13
URL       https://leetcode.com/problems/magical-string
Approach  String, BruteForce
"""

class Solution:
    def magicalString(self, n):
        s = [1, 2, 2]
        f = [1, 2, 2]
        toggle = 2
        f_idx = 2
        while(len(s) < n):
            toggle = 1 if toggle == 2 else 2
            k = f[f_idx]
            for i in range(k):
                s.append(toggle)
                f.append(toggle)
            f_idx += 1
        cnt = 0
        for i in range(n):
            if s[i] == 1:
                cnt += 1
        return cnt
