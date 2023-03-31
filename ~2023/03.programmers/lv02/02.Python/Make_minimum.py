def solution(A,B):
    return sum(a*b for a, b in zip(sorted(A), sorted(B, reverse = True)))

input_A = [1, 4, 2]
input_B = [5,4,4]

print(solution(input_A,input_B))