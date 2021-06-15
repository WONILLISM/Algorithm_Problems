from typing import List
#class Solution:
#	def generate(self, numRows: int) -> List[List[int]]:
#		answer = [[1] * i for i in range(1, numRows + 1)]
#		if numRows > 2:
#			for i in range(2, len(answer)):
#				for j in range(1, len(answer[i]) - 1):
#					answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j]
#		return answer
class Solution:
	def generate(self, numRows: int) -> List[List[int]]:
		def fac(n):
			if n == 0 or n == 1:
				return (1)
			return fac(n) * fac(n - 1)

		print(fac(3))
		return answer

sol = Solution()
print(sol.generate(5))
print(sol.generate(1))
