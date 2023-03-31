import sys
sys.setrecursionlimit(100000)

answer = []
m = {}  # idx번째 고객의 방 번호, 다음 방 번호

def find(i,key):
    global answer
    global m
    if key not in m:
        m[key] = key +1
        answer.append(key)
        return m[key]
    else:
        nk = find(i,m[key])
        m[key] = nk
        return nk

def solution(k, room_number):
    global answer
    global m
    for i in range(len(room_number)):
        key = room_number[i]    # 고객이 원하는 방 번호
        if key not in m:
            m[key] = key+1
            answer.append(key)
        else:
            m[key] = find(i,m[key])      

    return answer

input_k = 10
input_room_number = [1,3,4,1,3,1]

print(solution(input_k, input_room_number))