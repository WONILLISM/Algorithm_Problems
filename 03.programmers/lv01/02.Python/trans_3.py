def solution(n):
	answer = 0
	tmp = ""
	while n:
		tmp += str(n%3)
		n//=3
	tmp = tmp.lstrip('0')
	for i, t in enumerate(tmp):
		print(answer)
		answer += int(t) * 3 ** (len(tmp) -(i + 1))

	return answer
