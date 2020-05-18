dic = {i:hex(i)[2:].upper() for i in range(16)}
def change(number, n):
    global dic
    if number//n == 0: return dic[number]
    else: return change(number//n, n) + dic[number%n]

def solution(n, t, m, p):
    number, index = 0, 0
    answer = ''
    while 1:
        number_str = change(number, n)
        print(number_str)
        for num in number_str:
            if index == p-1: answer += num
            if len(answer)==t: return answer
            index = (index+1) % m
        number += 1

input_n = 2
input_t = 4
input_m = 2
input_p = 1

# input_n = 16
# input_t = 16
# input_m = 2 
# input_p	= 1	
# 02468ACE11111111

print(solution(input_n,input_t,input_m,input_p))