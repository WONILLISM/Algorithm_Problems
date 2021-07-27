class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        check = [1] * n
        check[0] = check[1] = 0
        for i in range(2, int(sqrt(n)) + 1):
            if check[i]:
                for j in range(i * i, n, i):
                    check[j] = 0
        return sum(check)
