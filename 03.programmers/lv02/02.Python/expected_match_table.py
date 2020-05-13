# 011 ^ 110 = 111
def solution(n,a,b):
    return ((a-1)^(b-1)).bit_length()

input_n = 8
input_a = 4
input_b = 5
print(solution(input_n,input_a,input_b))