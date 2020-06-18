def solution(arr):
    return [ v for i,v in enumerate(arr) if arr[i-1]!=arr[i]]
input_arr = [1,1,3,3,0,1,1]
print(solution(input_arr))
