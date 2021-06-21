from typing import List
class Solution:
	def generate(self, numRows: int) -> List[List[int]]:
		answer = [[1] * i for i in range(1, numRows + 1)]
		if numRows > 2:
			for i in range(2, len(answer)): # row
				for j in range(1, len(answer[i]) - 1): # colum
					answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j]
		return answer


sol = Solution()
print(sol.generate(5))
print(sol.generate(1))
