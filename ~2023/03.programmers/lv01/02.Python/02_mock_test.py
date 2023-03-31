def solution(answers):
    answer=[]
    res = [0,0,0]
    player = [[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    for i in range(len(answers)):
        if answers[i] == player[0][i%len(player[0])]: res[0]+=1
        if answers[i] == player[1][i%len(player[1])]: res[1]+=1
        if answers[i] == player[2][i%len(player[2])]: res[2]+=1
    max_val = max(res)
    for i in range(len(res)):
        if res[i] == max_val:
            answer.append(i+1)
    return sorted(answer)