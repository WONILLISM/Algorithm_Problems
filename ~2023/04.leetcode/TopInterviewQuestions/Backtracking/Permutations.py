class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        answer = []
        res = []
        visit = [False] * n
        def permutations(nums, curr, depth, n):
            if depth == n:
                answer.append(list(res))
                return
            for nxt in range(len(nums)):
                if visit[nxt] == False:
                    visit[nxt] = True
                    res.append(nums[nxt])
                    permutations(nums, nxt, depth + 1, n)
                    res.pop()
                    visit[nxt] = False
        permutations(nums, 0, 0, n)
        return answer
