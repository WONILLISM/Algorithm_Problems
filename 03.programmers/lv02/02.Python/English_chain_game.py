def solution(n, words):
    for i in range(1, len(words)):
        if words[i-1][-1] != words[i][0] or words[i] in words[:i]: return [(i%n)+1, (i//n)+1]
    else: return [0,0]

input_n = 3
input_words = ["tank", "kick", "know", "wheel", "land",
                "dream", "mother", "robot", "tank"]
# input_n = 2
# input_words = ["hello", "one", "even", "never", "now", "world", "draw"]

print(solution(input_n, input_words))
