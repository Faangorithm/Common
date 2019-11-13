//Author Yunsoo Jung
//Date 2019-11-13
//https://leetcode.com/problems/knight-dialer/
//Approach Dp, bottomup

k = 10 ** 9 + 7
def bottom_up(n):
    prev = [1] * 10
    cur = [0] * 10

    for i in range(n):
        for i in range(10):
            cur[0] = prev[4] + prev[6]
            cur[1] = prev[6] + prev[8]
            cur[2] = prev[7] + prev[9]
            cur[3] = prev[4] + prev[8]
            cur[4] = prev[0] + prev[3] + prev[9]
            cur[6] = prev[0] + prev[1] + prev[7]
            cur[7] = prev[2] + prev[6]
            cur[8] = prev[1] + prev[3]
            cur[9] = prev[2] + prev[4]
        prev = cur
        cur = [0] * 10
        
        for i in range(10):
            prev[i] = prev[i] % k
        print(prev)
    return prev

class Solution:
    def knightDialer(self, N):
        res = bottom_up(N - 1)
        ans = 0
        for i in range(10):
            ans += res[i]
        return ans % k
            
