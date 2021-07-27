class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        res = []
        def backtracking(nums, curr, depth, n):
            if depth == n:
                answer.append(list(res))
                return
            for nxt in range(curr, len(nums)):
                res.append(nums[nxt])
                backtracking(nums, nxt + 1, depth + 1, n)
                res.pop()
        for n in range(len(nums) + 1):
            backtracking(nums, 0, 0, n)
        return answer
