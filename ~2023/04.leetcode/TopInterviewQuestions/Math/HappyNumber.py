class Solution:
    def __init__(self):
        self.dp = {}
    def isHappy(self, n: int) -> bool:
        if n == 1:
            return True
        if n in self.dp.keys() and self.dp[n] == True:
            return False
        self.dp[n] = True
        res = 0
        while n>0:
            tmp=n%10
            res+=tmp**2
            n//=10
        return self.isHappy(res)
