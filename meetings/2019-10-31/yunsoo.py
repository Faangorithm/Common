"""
Author    Yunsoo Jung
Date      2019-10-31
URL       https://leetcode.com/problems/maximum-swap/
Approach  String, bucket
"""

def maximumSwap(x):
    bucket = [0] * 10
    char_x = list(str(x))
    n = len(char_x)
    
    for i in range(n):
        idx = int(char_x[i])
        bucket[idx] += 1
    rev_num = 9
    x_idx = 0
    
    while(rev_num >= 0):
        count = bucket[rev_num]
        if count == 0:
            rev_num -= 1
            continue
        val = int(char_x[x_idx])
        if val == rev_num:
            x_idx += 1
            bucket[rev_num] -= 1
        else:
            break
            
    for i in reversed(range(n)):
        if int(char_x[i]) == rev_num:
            # swap
            tmp = char_x[x_idx]
            char_x[x_idx] = char_x[i]
            char_x[i] = tmp
            break
            
    return int("".join(char_x))
                
            
            
    
