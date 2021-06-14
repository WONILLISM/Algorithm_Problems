from typing import List
class Solution:
	def moveZeroes(self, nums: List[int]) -> None:
		zero = 0
		for i in range(len(nums)):
			if nums[i] != 0:
				tmp = nums[i]
				nums[i] = nums[zero]
				nums[zero] = tmp
				zero += 1
		print(nums)
		"""
		Do not return anything, modify nums in-place instead.
		"""

sol = Solution()
sol.moveZeroes([0,1,0,3,12])
