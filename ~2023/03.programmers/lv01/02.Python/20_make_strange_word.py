def solution(s):
    answer = ""
    idx = 0
    tmp =""
    for i in range(len(s)):
        tmp += s[i].upper() if idx%2==0 else s[i].lower()
        if s[i]==" ":
            idx = 0
            answer +=tmp
            tmp = ""
        else: idx+=1
    else: answer +=tmp
    return answer
        

print(solution("try hello world"))