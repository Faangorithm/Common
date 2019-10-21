//Author    Yunsoo Jung
//Date      2019-10-19
//URL       https://leetcode.com/problems/remove-comments/ 
//Approach  String
class Solution:
    def removeComments(self, source):
        n = len(source)
        ans = []
        multiComment = False
        for i in range(n):
            source_line = source[i]
            m = len(source_line)
            j = 0
            if not multiComment:
                agg = []
            while(j < m):
                token = source_line[j : j + 2] if j != m - 1 else source_line[j]
                
                if multiComment:
                    if token == "*/":
                        multiComment = False
                        j += 2
                    else:
                        j += 1
                elif token == "//":
                    break
                elif token == "/*":
                    multiComment = True
                    j += 2
                else:
                    agg.append(source_line[j])
                    j += 1
                    
            if multiComment:
                continue
            cur_line = "".join(agg)
            if cur_line != "":
                ans.append(cur_line)
        return ans
