def solution(progresses, speeds):
    answer = []
    max_day = 0
    for p, s  in zip(progresses, speeds):
        day = (99 - p)//s +1
        if len(answer) == 0 or max_day< day:
            max_day = day
            answer.append(1)
        else: answer[-1]+=1

    return answer

input_progresses = [93, 30, 55]
input_speeds = [1, 30, 5]
print(solution(input_progresses, input_speeds))