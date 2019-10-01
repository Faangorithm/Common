#Author    Yunsoo Jung
#Date      2019-10-01
#URL       https://leetcode.com/problems/permutation-in-string/
#Approach  Sliding Window, String

class Solution:
    def checkInclusion(self, s1, s2):
        n1 = len(s1)
        n2 = len(s2)
        if n1 > n2:
            return False

        container = {}
        for alpha in s1:
            if alpha in container.keys():
                container[alpha] += 1
            else:
                container[alpha] = 1

        slots = 0
        for i in range(n1):
            char = s2[i]
            if char in container.keys():
                container[char][1] -= 1
                slots -= 1

        if slots == n1:
            return True

        for end in range(n1, n2):
            start = end - n1
            alpha = s2[start]
            if alpha in container.keys():
                require = container[alpha][0]
                have = container[alpha][1]
                if require >= have:
                    slots -= 1
                container[alpha][1] -= 1

            alpha = s2[end]
            if alpha in container.keys():
                require = container[alpha][0]
                have = container[alpha][1]
                if require > have:
                    slots += 1
                container[alpha][1] += 1
            if slots == n1:
                return True
        return False
