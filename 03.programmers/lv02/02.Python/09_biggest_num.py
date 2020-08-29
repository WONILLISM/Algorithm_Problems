def comp(a, b):
    return a+b > b+a


def solution(numbers):
    numbers.sort(key=comp)
    # numbers = sorted(numbers)
    print(numbers)


input_numbers = [3, 30, 34, 5, 9]
print(solution(input_numbers))
 