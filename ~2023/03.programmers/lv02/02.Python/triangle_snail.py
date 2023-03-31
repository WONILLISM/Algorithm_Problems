

def solution(n):
	answer = []
	for i in range(n):
		answer.append([0 for _ in range(i + 1)])
	x, y = 0, -1
	idx = 1
	stat = 0
	for i in range(n, 0, -1):
		for j in range(i):
			# print(y, x)
			if stat % 3 == 0:
				y += 1
			elif stat % 3 == 1:
				x += 1
			else:
				y -= 1
				x -= 1
			answer[y][x] = idx
			idx += 1
		stat += 1
	res = []
	for i in answer:
		res += i
	return res


print(solution(4))