def solution(array, commands):
    return [ sorted(array[i[0]:i[1]])[i[2]-1] for i in commands ]
input_array = [1, 5, 2, 6, 3, 7, 4]
input_commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
print(solution(input_array, input_commands))
