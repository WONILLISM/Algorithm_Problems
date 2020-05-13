answer =0
def chk_prime(x):
    i = 2
    while(i*i<=x):
        if x%i == 0: return False
        i+=1
    return True
def process(nums,chk,i,sum,cnt):
    if cnt>3: return
    if cnt == 3 and chk_prime(sum):
        global answer
        answer+=1
        return
    for j in range(i,len(nums)):
        if not chk[j] :
            chk[j] = True
            process(nums, chk, j, sum + nums[j],cnt +1)
            chk[j] = False

def solution(nums):
    global answer
    n = len(nums)
    chk = [0]*n
    process(nums, chk,0,0,0)
    return answer

input_nums = [1,2,7,6,4]
print(solution(input_nums))