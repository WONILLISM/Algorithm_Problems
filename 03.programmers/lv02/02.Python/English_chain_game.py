def solution(n, words):
    for i in range(1, len(words)):
        if words[i-1][-1] != words[i][0] or words[i] in words[:i]: return [(i%n)+1, (i//n)+1]
    else: return [0,0]
# def solution(n, words):
#     answer = [1,1]
#     s = set()
#     for i in range(len(words)):
#         answer[0] = i%n +1
#         # print(answer)
#         key = words[i]
#         if i>0 and words[i-1][-1] != key[0]:
#             return answer
#         if len(s) and key in s:
#             return answer
#         else :
#             s.add(key)
#             if i>0 and ((i+1)%n == 0) :
#                 answer[1] +=1
#     return [0,0]

input_n = 3
input_words = ["tank", "kick", "know", "wheel", "land",
                "dream", "mother", "robot", "tank"]
# input_n = 2
# input_words = ["hello", "one", "even", "never", "now", "world", "draw"]

print(solution(input_n, input_words))
