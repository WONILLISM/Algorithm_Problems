class Solution:
    def __init__(self):
        dp=[]
    def memoization(self, n: int) -> int:
        if n==1 or n==2:
            return n
        if self.dp[n]:
            return self.dp[n]
        self.dp[n]=self.memoization(n-1) + self.memoization(n-2)
        return self.dp[n]
    def climbStairs(self, n: int) -> int:
        self.dp = [0 for _ in range(n+1)]
        return self.memoization(n)
    def climbStairs(self, n: int) -> int:
        a, b = 1, 1
        for i in range(n):
            a, b=b, a+b
        return a
