from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur , answer = -(10 ** 5), nums[0]
        for x in nums:
            cur = max(x,cur+x)
            answer = max(answer,cur)
        return answer

    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        for i in range(1,n):
            dp[i] = max(dp[i-1] + nums[i], nums[i])
        return max(dp)

sol = Solution()
print(sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
