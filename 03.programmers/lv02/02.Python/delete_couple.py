def solution(s):
    answer = 0
    stack = []
    for c in s:
        if len(stack) and stack[-1]==c:
            stack.pop()
        else: stack.append(c)
    answer = 0 if len(stack) else 1
    return answer