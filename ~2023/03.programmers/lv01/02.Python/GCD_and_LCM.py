def solution(n, m):
    GCD = lambda x, y : y if x%y == 0 else GCD(y,x%y)
    return [a*b//GCD(n,m) , GCD(n,m)]