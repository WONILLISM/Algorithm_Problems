def solution(msg):
    answer = []
    tmp = {chr(e + 64): e for e in range(1, 27)}
    num = 27
    while msg:
        r = 1
        while msg[:r] in tmp.keys() and r <= len(msg):
            r += 1
        r -= 1
        if msg[:r] in tmp.keys():
            answer.append(tmp[msg[:r]])
            tmp[msg[:r + 1]] = num
            num += 1
        msg = msg[r:]
    return answer

input_msg = "KAKAO"
#[11, 1, 27, 15]
input_msg = "TOBEORNOTTOBEORTOBEORNOT"
#[20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34]
print(solution(input_msg))
