def solution(s):
    answer = 0
    stack = []
    for c in s:
        if len(stack):
            if stack[-1]==c:
                stack.pop()
                answer +=2
            else: stack.append(c)
        else: stack.append(c)
    answer = 0 if len(stack) else 1

    return answer

input_s="baabaa"
print(solution(input_s))