def solution(n):
    answer = []
    for i in range(n):
        tmp = []
        if len(answer) == 0 :
            answer = [0]
            continue
        tmp = answer
        tmp.append(0)  
        for j in range(len(answer)-2,-1,-1):
            if answer[j] == 0 : tmp.append(1)
            else: tmp.append(0)      
        
        answer = tmp
    return answer
input_n = 3
print(solution(input_n))