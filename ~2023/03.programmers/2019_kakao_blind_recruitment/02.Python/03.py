def isPossible(l, cur):
    for a in l:
        if (a&cur) == a: return False
    return True
def solution(relation):
    answer = []
    row = len(relation)
    col = len(relation[0])

    # 조합으로 나올 수 있는 모든 경우
    for i in range(1,1<<col):   
        s = set()
        for j in range(row):
            cur =""
            for k in range(col):
                #print("{0:b}".format(i).zfill(col)+" "+"{0:b}".format(1<<k).zfill(col))
                if i&(1<<k):
                    cur +=relation[j][k]
            s.add(cur)
        if len(s) == row and isPossible(answer,i):
            answer.append(i)
    return len(answer)

input_relation = [
    ["100","ryan","music","2"],
    ["200","apeach","math","2"],
    ["300","tube","computer","3"],
    ["400","con","computer","4"],
    ["500","muzi","music","3"],
    ["600","apeach","music","2"]
]
print(solution(input_relation))