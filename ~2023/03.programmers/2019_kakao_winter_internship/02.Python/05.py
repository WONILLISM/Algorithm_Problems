def solution(stones, k):
    left =1
    right = max(stones)
    while left <= right:
        mid = int((left + right)/2);
        cnt = 0
        flag = False
        for st in stones:
            if st - mid <=0: cnt+=1
            else: cnt = 0
            if cnt >= k:
                flag = True
                break

        if flag: right = mid -1 
        else: left = mid +1
    return left

input_stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1]
input_k = 3
print(solution(input_stones,input_k))
