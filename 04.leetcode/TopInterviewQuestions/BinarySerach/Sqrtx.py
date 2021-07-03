class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x

        left, right = 1, x
        while left <= right:
            mid = (left + right) // 2
            pow_mid = mid * mid
            if pow_mid == x:
                return mid
            elif pow_mid < x:
                left = mid + 1
            elif pow_mid > x:
                right = mid - 1
        return right
