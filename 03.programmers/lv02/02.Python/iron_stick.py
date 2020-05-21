def solution(arrangement):
    answer = 0
    cnt = 0
    for i in range(len(arrangement)):
        c = arrangement[i]
        if c=='(': cnt+=1
        else:
            cnt-=1
            if arrangement[i-1]=='(': answer +=cnt
            else answer+=1
            
    return answer

input_arg = "()(((()())(())()))(())"
print(solution(input_arg))