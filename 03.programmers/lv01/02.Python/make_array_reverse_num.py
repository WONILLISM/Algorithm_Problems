def solution(n):
    return [int(i) for i in str(n)][::-1]

input_n = 12345
print(solution(input_n))