class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        mid = 0
        answer = 0
        while left <= right:
            mid = (left + right) // 2
            if sum(i <= mid for i in nums) > mid:
                answer = mid
                right = mid - 1
            else:
                left = mid + 1
        return answer
