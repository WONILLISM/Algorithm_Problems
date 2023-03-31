def solution(new_id):
	# step 1
	answer = new_id.lower()
	
	# step 2
	tmp = "-_."
	tmp2 = ''.join(x for x in answer if (x.isdigit() or x.isalpha()) or (x in tmp))

	# step 3
	answer = ""
	flag = False
	for x in tmp2:
		if x == '.':
			if flag == False:
				flag = True
				answer += x
		else:
			flag = False
			answer += x       
	
	# step 4
	tmp2 = answer.strip(".")
	
	# step 5
	if tmp2 == "":
		tmp2 = "a"
	
	# step 6
	if len(tmp2) >= 16:
		answer = tmp2[:15]
	else:
		answer = tmp2
	tmp2 = answer.strip(".")
	# step 7
	if len(tmp2) <= 2:
		while len(tmp2) < 3:
			tmp2 += tmp2[-1] 
	answer = tmp2
	return answer


print(solution("abcdefghijklmn.p"))
# print(solution("...!@BaT#*..y.abcdefghijklm"))
# print(solution("z-+.^."))