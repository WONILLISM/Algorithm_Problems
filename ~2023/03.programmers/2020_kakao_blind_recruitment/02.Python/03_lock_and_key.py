def solution(key, lock):
    answer = True
    key_size = len(key)
    lock_size = len(lock)
    
    for i in range(-key_size + 1 , key_size):
        print(i);

    return answer

input_key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
input_lock = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
solution(input_key, input_lock)