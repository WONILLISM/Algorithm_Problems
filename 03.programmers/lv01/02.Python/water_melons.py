def solution(n):
    return "".join(["?" if i%2==0 else "?" for i in range(n) ])