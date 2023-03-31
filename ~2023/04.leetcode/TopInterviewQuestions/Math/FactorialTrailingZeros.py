from time import time
import math

def func(n):
    i, answer = 5, 0
    while i<=n:
        answer+=n//i
        i*=5
    return answer

t = time()
func(12)
print(time() - t)
