def solution(s):
    return s.isdigit() and len(s) in (4,6)

input_s = "a1234"
print(solution(input_s))