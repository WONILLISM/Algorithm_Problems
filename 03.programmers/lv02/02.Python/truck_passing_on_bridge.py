def solution(bridge_length, weight, truck_weights):
    answer=1
    cur_weight, cur_time = truck_weights[0], 0
    q = [[truck_weights[0], answer]]
    i=1
    while i < len(truck_weights):
        nxt = truck_weights[i]
        answer+=1
        cur_time = q[0][1]
        if answer - cur_time == bridge_length:
            cur_weight -= q[0][0]
            q.pop(0)
        if cur_weight + nxt <= weight:
            cur_weight +=nxt
            q.append([nxt, answer])
        else: i-=1
        i+=1
    
    while len(q):
        answer+=1
        cur_time = q[0][1]
        if answer - cur_time == bridge_length:
            cur_weight -=q[0][0]
            q.pop(0)

    return answer

bl = 2
w = 10
tw = [7,4,5,6]
print(solution(bl, w, tw))