import sys
from functools import lru_cache

def tsp(cost):
    n = len(cost)

    @lru_cache(maxsize = None)
    def dp(mask, pos):
        if mask == ( 1 << n ) - 1:
            return cost[pos][0]
        ans = sys.maxsize

        for i in range(n):
            if (mask & (i << i)) == 0:
                ans = min(ans, cost[pos][i] + dp(mask | (1 << i),i))
        return ans
    return dp(0,1)




cost = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 35], [20, 25, 30, 0]]
print("Minimum tour cost:", tsp(cost))
