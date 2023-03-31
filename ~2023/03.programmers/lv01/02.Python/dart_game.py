def solution(dartResult):
    answer = []
    for i, c in enumerate(dartResult):
        if c.isdigit(): 
            if c==0 and dartResult[i-1] == 1:
                answer.pop(-1)
                answer.append(10)
            else:
                answer.append(int(c))
        else:
            if c == 'S': continue
            elif c == 'D': answer[-1] = answer[-1]**2
            elif c == 'T': answer[-1] = answer[-1]**3
            elif c == '#': answer[-1]*=-1
            elif c == '*':
                answer[-1] *=2
                if len(answer) > 1 : answer[-2] *=2
                    
    return sum(answer)

input_dartRsult = "1S2D*3T"
print(solution(input_dartRsult))
