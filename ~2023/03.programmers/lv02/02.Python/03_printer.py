def solution(pri, loc):
    answer = 0
    while len(pri):
        M = max(pri)
        cur = pri.pop(0)
        if cur == M:
            answer+=1
            if loc == 0: break
            else: loc -=1
        else:
            if loc == 0: loc = len(pri)
            pri.append(cur)
    return answer

input_pri =[1,1,9,1,1,1]
input_loc = 0

print(solution(input_pri, input_loc))