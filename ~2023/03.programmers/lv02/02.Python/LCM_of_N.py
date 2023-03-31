def solution(arr):
    answer = arr[0]
    GCD = lambda a, b : b if a%b==0 else GCD(b,a%b)
    LCM = lambda a, b : int(a*b/GCD(a,b))
    for i in range(1,len(arr)):
        answer = LCM(answer,arr[i])
    return answer

input_arr = [2,6,8,14]
print(solution(input_arr))

# def GCD(a,b): return b if a%b==0 else GCD(b,a%b)
# def LCM(a,b): return int((a*b)/GCD(a,b))
# def solution(arr):
#     answer = arr[0]
#     for i in range(1,len(arr)):
#         answer = LCM(answer,arr[i])
#     return answer