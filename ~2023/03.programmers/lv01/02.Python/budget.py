def solution(d, budget):
    d.sort()
    for i, x in enumerate(d):
        if sum(d[:i+1]) > budget: return i
    return len(d)
input_d = [1,3,2,5,4]
input_budget = 9
print(solution(input_d, input_budget))