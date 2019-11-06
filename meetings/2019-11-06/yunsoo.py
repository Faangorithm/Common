//Author Yunsoo Jung
//Date 2019-11-06
//URL https://leetcode.com/problems/gas-station
//Approach Twopointer, PartialSum

class Solution:
    def canCompleteCircuit(self, gas, cost):
        n = len(gas)
        net_cost = [0] * 2 * n

        for i in range(2 * n):
            j = i % n
            net_cost[i] = gas[j] - cost[j]

        start = 0
        end = 1
        net = net_cost[start]
        while(end < 2 * n and (end - start) < n):
            while(net < 0 and end > start):
                net -= net_cost[start]
                start += 1
            net += net_cost[end]
            end += 1
            
            
        if end - start == n and net >= 0:
            return start
        return -1
