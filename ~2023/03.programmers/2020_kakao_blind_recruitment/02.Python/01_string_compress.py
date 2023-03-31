def solution(s):
    answer = len(s)
    for i in range(1, len(s)//2 + 1):
        cur = s[0:i]
        cnt = 1
        l = i
        tmp = 0
        while 1:
            next_str = s[l:l+i]
            if next_str == cur: cnt+=1
            else:
                if cnt!=1: tmp+=len(str(cnt))
                tmp += i
                cur = next_str
                cnt = 1
            
            if l+i>=len(s):
                if cnt!=1: tmp += len(str(cnt))
                tmp += len(s) - l
                break
            l+=i
        answer = min(answer, tmp)

    return answer


input_s = "aabbcccc"
print(solution(input_s))