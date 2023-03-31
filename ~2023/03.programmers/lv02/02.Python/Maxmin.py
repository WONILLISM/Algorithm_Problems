def solution(s):
    s = list(map(int,s.split()))
    return str(min(s)) + " " + str(max(s))


input_s = "1 2 3 4"

print(solution(input_s))