#!/usr/bin/env python3
class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
        cur = [[0 for j in range(G+1)] for i in range(P+1)]
        cur2 = [[0 for j in range(G+1)] for i in range(P+1)]
        cur[0][0] = 1
        MOD = 10**9 + 7
        
        for p0, g0 in zip(profit, group):
            # p0, g0: the current crime profit and group size
            # Deep copy cur to cur2
            for i in range(P+1):
                for j in range(G+1):
                    cur2[i][j] = cur[i][j]
            
            for p1 in range(P+1):
                # p1: the current profit
                # p2: the new profit after commiting this crime
                p2 = min(p1 + p0, P)
                for g1 in range(G - g0 + 1):
                    # g1: the current group size
                    # g2: the new group size after committing this crime
                    g2 = g1 + g0
                    cur2[p2][g2] += cur[p1][g1]
                    cur2[p2][g2] %= MOD
            # Swap cur and cur2
            tmp = cur2
            cur2 = cur
            cur = tmp
        # Sum all schemes with profit P and group size 0 <= g <= G
        return sum(cur[P]) % MOD

