def solution(n):
    return int("".join(reversed(sorted(str(n)))))

input_n = 118372
pirnt(solution(input_n))