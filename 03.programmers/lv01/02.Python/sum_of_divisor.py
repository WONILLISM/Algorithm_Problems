def solution(n):
    return sum([i for i in range(1,n+1) if n%i==0])

input_n = 12
print(solution(input_n))