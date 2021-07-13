from typing import List
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)+1
        total=sum(nums)
        answer = (n-1)*(n)//2
        if total == answer-total:
            if 0 not in nums:
                return 0
            else:
                return n-1
        else:
            return answer-total
