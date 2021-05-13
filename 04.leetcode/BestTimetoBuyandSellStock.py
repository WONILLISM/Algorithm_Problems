from	typing	import List

class Solution121:
	def maxProfit(self, prices: List[int]) -> int:
		answer = 0
		size = len(prices)
		if len(prices) == 1:
			return answer
		l = 0
		r = l + 1
		while r < size:
			if prices[l] > prices[r]:
				l += 1
			answer = max(answer, prices[r] -  prices[l])
			r += 1
		return answer

# 7, 1, 5, 3, 1, 6, 4
# l  r
#    l  r
#    l     r
#    l        r
#    l           r
#    l              r
