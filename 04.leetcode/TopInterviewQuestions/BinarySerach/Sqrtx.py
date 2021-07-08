class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x

        left, right = 1, x
        mid = 0
        while left <= right:
            mid = (left + right) // 2
            pow_mid = mid * mid
            print(f"left:{left}, right:{right}, mid:{mid}")
            if pow_mid == x:
                return mid
            elif pow_mid < x:
                left = mid + 1
            elif pow_mid > x:
                right = mid - 1
        print("------------------------------------------------")
        print(f"left:{left}, right:{right}, mid:{mid}")
        return right

sol = Solution()
print(sol.mySqrt(25))
