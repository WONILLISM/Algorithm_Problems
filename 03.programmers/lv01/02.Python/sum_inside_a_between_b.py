def solution(a, b):
    if (abs(a-b) + 1)%2 == 0: return (a+b)*((abs(a-b)+1)//2)
    else: return (a+b)*(abs(a-b)//2) + (a+b)//2    

input_a, input_b = 3,5
print(solution(input_a, input_b))