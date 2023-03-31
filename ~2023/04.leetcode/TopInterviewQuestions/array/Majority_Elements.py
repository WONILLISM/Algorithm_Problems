from typing import List

class Solution:
	def majorityElement(self, nums: List[int]) -> int:
		d = {}
		max_key = 0;
		max_val = 0;
		for num in nums:
			if num not in d:
				d[num] = 1
			else:
				d[num] += 1

			if max_val < d[num]:
				max_val = d[num]
				max_key = num
		return max_key

sol = Solution()
print(sol.majorityElement([3,2,3]))
print(sol.majorityElement([2,2,1,1,1,2,2]))
