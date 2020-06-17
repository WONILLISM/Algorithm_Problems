def solution(a, b):
    day = ["FRI","SAT","SUN","MON","TUE","WED","THU"]
    date_of_month = [31,29,31,30,31,30,31,31,30,31,30,31]
    return day[(sum([ date_of_month[i] for i in range(a-1)]) + b -1)%7]

input_a, input_b = 5, 24
print(solution(input_a,input_b))