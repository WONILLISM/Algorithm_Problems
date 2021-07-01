class Solution:
    def twoSum1(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            answer = nums[i]
            for j in range(i + 1, len(nums)):
                answer += nums[j]
                if answer == target:
                    return [i, j]
                answer -= nums[j]
        return []

    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        tmp = {}
        for i, x in enumerate(nums):
            if target - x in tmp:
                return [tmp[target - x], i]
            else:
                tmp[x] = i
        return []
