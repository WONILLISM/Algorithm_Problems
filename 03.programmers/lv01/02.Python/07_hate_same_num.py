def solution(arr):
    return [arr[0]] + [arr[i] for i in range(1,len(arr)) if arr[i-1] != arr[i]]
input_arr = [1,1,3,3,0,1,1]
print(solution(input_arr))
