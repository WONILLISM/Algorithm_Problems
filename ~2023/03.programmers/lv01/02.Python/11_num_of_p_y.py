def solution(s):
    return s.count("p" or "P") == s.count("y" or "Y")

input_s = "pPoooyY"
print(solution(input_s))