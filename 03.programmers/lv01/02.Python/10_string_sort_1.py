def solution(strings, n):
    return sorted([s for s in strings],key = lambda a:[a[n],a])

input_strings = ["sun", "bed", "car"]
input_n = 1
print(solution(input_strings, input_n))