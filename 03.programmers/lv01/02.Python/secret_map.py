def solution(n, arr1, arr2):
    return [ "{0:b}".format((arr1[i] | arr2[i])).zfill(n).translate(str.maketrans("10","# ")) for i in range(n)]

input_n = 6
input_arr1 = [46, 33, 33, 22, 31, 50]
input_arr2 = [27, 56, 19, 14, 14, 10]

print(solution(input_n,input_arr1,input_arr2))