def solution(arr):
    return list(filter(lambda a: a!=min(arr),arr)) if len(arr) >1 else [-1]

input_arr = [4,3,2,1]
print(solution(input_arr))