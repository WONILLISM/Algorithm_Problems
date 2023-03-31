class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0
        sign = 1 if x > 0 else -1
        x = abs(x)
        answer = 0
        while x:
            answer *= 10
            answer += x % 10
            x //= 10
        answer = answer * sign
        if answer > 2147483647 or answer < -2147483648:
            return 0
        return answer
