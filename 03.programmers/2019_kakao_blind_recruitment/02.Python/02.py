def solution(N, stages):
    answer = []
    stages.sort()
    size = len(stages)
    tmp = {i : 0 for i in range(1,N+1)}
    for i in stages: 
        if i != N+1 : tmp[i] +=1
    for i in tmp.items():
        key = i[0]
        value = i[1]
        if size==0 : break
        tmp[key] = value/size
        size-=value    

    tmp = sorted(tmp, key=lambda k: tmp[k], reverse=True)
    answer = tmp
    return answer

# input_N = 5
# input_stages = [2,1,2,6,2,4,3,3]
input_N = 4
input_stages = [4,4,4,4,4]
print(solution(input_N , input_stages))