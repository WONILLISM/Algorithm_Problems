class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []
        res = []
        def backtrack(left, right):
            if len(res) == 2 * n:
                answer.append("".join(res))
                return
            if left < n:
                res.append("(")
                backtrack(left+1, right)
                res.pop()
            if right < left:
                res.append(")")
                backtrack(left, right+1)
                res.pop()
        backtrack(0, 0)
        return answer
