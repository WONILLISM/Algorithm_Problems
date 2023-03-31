def solution(arr, divisor):
    return sorted([ans for ans in arr if ans%divisor == 0]) or [-1] # 앞의 조건이 거짓일 때 뒤에 것 반환

input_arr = [5,9,7,10]
input_divisor = 5
print(solution(input_arr, input_divisor))