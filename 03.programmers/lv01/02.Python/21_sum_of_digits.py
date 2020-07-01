def solution(n):
    #return sum([int(i) for i in str(n)])
    return sum(map(int,str(n)))
print(solution(123))