def solution(n, lost, reserve):
    answer = 0
    students = [1 for i in range(n+2)]
    for l in lost: students[l] -=1
    for r in reserve: students[r] +=1
    for i in range(1,n+1):
        if students[i] == 0:
            if students[i-1]==2: 
                students[i-1] = 1
                students[i] = 1
            elif students[i+1] == 2: 
                students[i] = 1
                students[i+1] = 1
    for i in range(1,n+1):
        if students[i]: 
            answer+=1
    return answer

input_n = 5
input_lost = 2,4
input_reserve = 1,3,5
print(solution(input_n, input_lost, input_reserve))