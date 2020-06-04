def solution(participant, completion):
    participant.sort()
    print(participant)

input_participant = ["mislav", "stanko", "mislav", "ana"]
input_completion = ["stanko", "ana", "mislav"]
print(solution(input_participant, input_completion))