def solution(s):
    answer = ""
    answer += s[0].upper()
    for i in range(1, len(s)):
        answer += s[i].upper() if s[i-1] == ' ' else s[i].lower()
    return answer

input_s = "3people unFollowed me"
print(solution(input_s))