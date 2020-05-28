def solution(n):
    answer = []
    num = [1,2,4]
    while n:
        n-=1
        answer.append(str(num[n%3]))
        n//=3
    return "".join(reversed(answer))

print(solution(4))