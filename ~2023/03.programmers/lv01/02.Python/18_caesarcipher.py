def solution(s, n):
    answer = ""
    for c in s:
        if c == " ":answer+=" "
        else :
            if c.isupper() :
                if ord(c) + n > ord("Z") : answer += chr(ord("A")-1 - ord("Z") + ord(c) + n)
                else: answer += chr(ord(c) + n)
            elif c.islower() :
                if ord(c) + n > ord("z") : answer += chr(ord("a")-1 - ord("z") + ord(c) + n)
                else: answer += chr(ord(c) + n)
    return answer
    

input_s = "AB"
input_n = 1
print(solution(input_s,input_n))