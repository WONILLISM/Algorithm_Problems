import heapq


def solution(scoville, K):
    answer = 0
    a = 0
    heapq.heapify(scoville)

    while scoville[0] < K:
        if len(scoville) == 1:
            return -1
        a = heapq.heappop(scoville)
        scoville.append(a + heapq.heappop(scoville) * 2)
        answer += 1

    return answer


input_scoville = [1, 2, 3, 9, 10, 12]
input_K = 7
print(solution(input_scoville, input_K))
