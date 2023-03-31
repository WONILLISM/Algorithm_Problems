def solution(numbers, hand):
	answer = ''
	location = {
		'1':(0,0), '2':(0,1), '3':(0,2),
		'4':(1,0), '5':(1,1), '6':(1,2),
		'7':(2,0), '8':(2,1), '9':(2,2),
		'*':(3,0), '0':(3,1), '#':(3,2)
	}

	lastL = '*'
	lastR = '#'
	for n in numbers:
		if n in [1,4,7]:
			answer += 'L'
			lastL = str(n)
		elif n in [3,6,9]:
			answer += 'R'
			lastR = str(n)
		else:
			distR = abs(location[lastR][0] - location[str(n)][0]) + abs(location[lastR][1] - location[str(n)][1])

	return answer

print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))

#def solution(numbers, hand):
#	answer = ''
#	lastL = 10
#	lastR = 12

#	for n in numbers:
#		if n in [1,4,7]:
#			answer+='L'
#			lastL = n
#		elif n in [3,6,9]:
#			answer+='R'
#			lastR = n
#		else:
#			n = 11 if n == 0 else n

#			absL = abs(n-lastL)
#			absR = abs(n-lastR)

#			if sum(divmod(absL, 3)) > sum(divmod(absR, 3)):
#				answer+='R'
#				lastR = n
#			elif sum(divmod(absL, 3)) < sum(divmod(absR, 3)):
#				answer +='L'
#				lastL = n
#			else:
#				if hand == 'left':
#					answer+='L'
#					lastL = n
#				else:
#					answer+='R'
#					lastR = n

#	return answer
