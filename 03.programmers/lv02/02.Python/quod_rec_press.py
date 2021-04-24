def solution(arr):
    global answer
    answer = [0,0]
    n = len(arr)
    recur(0,0,n,arr)
    
    return answer

def recur(y, x, n, arr):
    global answer
    flag = arr[y][x]
    
    for i in range(y, y + n):
        for j in range(x, x + n):
            if arr[i][j] != flag:
                nn = n//2
                recur(i, j, nn, arr)
                recur(i, j + nn, nn, arr)
                recur(i + nn, j, nn, arr)
                recur(i + nn, j + nn, nn, arr)
                return
    answer[flag] += 1
print(solution([[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]))