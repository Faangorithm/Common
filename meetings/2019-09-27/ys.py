#Author Yunsoo
#Date   2019-09-27

INF = 987654321
def pick(idx, arr, target, num_picked, local_sum):
    if num_picked == 3:
        return local_sum
    if idx >= len(arr):
        return INF
    
    m1 = pick(idx + 1, arr, target, num_picked + 1, local_sum + arr[idx])
    m2 = pick(idx + 1, arr, target, num_picked, local_sum)
    if (abs(target - m1) < abs(target - m2)):
        return m1
    return m2

class Solution(object):
    def threeSumClosest(self, nums, target):
        return pick(0, nums, target, 0, 0)
        
