def solution(n):
    answer =0
    MOD = 1234567
    dp = [0 for i in range(n+1)]
    for i in range(n+1):
        if i==0: dp[i] = 0
        elif i==1: dp[i]=1
        elif not dp[i]: dp[i] =(dp[i-1]+dp[i-2])%MOD
    
    answer = dp[n]
    return answer

input_n =  12
print(solution(input_n))