def solution(heights):
    answer =[0]
    for i in range(1,len(heights)):
        chk = False
        for j in range(len(heights[:i])-1,-1,-1):
            if(heights[j] > heights[i]):
                chk = True
                answer.append(j+1)
                break
        if chk==False : answer.append(0)
    return answer
input_heights = [6,9,5,7,4]
print(solution(input_heights))