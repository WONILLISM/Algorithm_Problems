def solution(s):
    answer = []
    s = s[2:-2]
    s = s.split("},{")
    s.sort(key = len)
    for i in s:
        ii = i.split(',')
        for j in ii:
            if int(j) not in answer:
                answer.append(int(j))
    return answer

input_s = "{{2},{2,1},{2,1,3},{2,1,3,4}}" 
#input_s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"
#input_s = "{{123}}"
#input_s = "{{20,111},{111}}"
print(solution(input_s))