from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        l, r = 0, n - 1
        answer = 0
        while l < r:
            answer = max(answer, (r-l) * min(height[r], height[l]))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return answer

sol = Solution()
print(sol.maxArea([1,8,6,2,5,4,8,3,7]))
