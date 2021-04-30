#def solution(n):
#	answer = 0
#	tmp = ""
#	while n:
#		tmp += str(n%3)
#		n//=3
#	tmp = tmp.lstrip('0')
#	for i, t in enumerate(tmp):
#		print(answer)
#		answer += int(t) * 3 ** (len(tmp) -(i + 1))

#	return answer


# https://codetorial.net/tips_and_examples/int_function.html
# 파이썬 int()사용법
def solution(n):
	answer = 0
	tmp = ""
	while n:
		tmp += str(n%3)
		n//=3
	answer = int(tmp, 3)
