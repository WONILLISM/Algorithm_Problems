def solution(dartResult):
    answer = []
    for i, c in enumerate(dartResult):
        if c.isdigit(): 
            if dartResult[i+1].isdigit(): 
                answer.append(int(dartResult[i:i+1]))
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
