def solution(arr1, arr2):
    return [[sum(a*b for a, b in zip(arr1_row,arr2_col)) for arr2_col in zip(*arr2)] for arr1_row in arr1]

input_arr1 = [[1, 4], [3, 2], [4, 1]]
input_arr2 = [[3, 3], [3, 3]]

print(solution(input_arr1,input_arr2))