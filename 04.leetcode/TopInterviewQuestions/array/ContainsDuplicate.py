from typing import List
class Solution:
	def containsDuplicate(self, nums: List[int]) -> bool:
		return len(set(nums)) != len(nums)
#class Solution:
#	def containsDuplicate(self, nums: List[int]) -> bool:
#		answer = False
#		tmp = set(nums)
#		if len(nums) != len(tmp):
#			answer = True
#		return answer
#class Solution:
#	def containsDuplicate(self, nums: List[int]) -> bool:
#		answer = False
#		nums.sort()
#		cur = nums[0]
#		for i in range(1,len(nums)):
#			if nums[i] != cur:
#				cur = nums[i]
#			else:
#				answer = True
#				break
#		return answer


sol = Solution()
print(sol.containsDuplicate([1,2,3,1]))
print(sol.containsDuplicate([1,2,3,4]))
print(sol.containsDuplicate([1,1,1,3,3,4,3,2,4,2]))
