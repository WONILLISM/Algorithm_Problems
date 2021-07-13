class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        answer = 0
        size = len(columnTitle)
        for i in range(size):
            x = ord(columnTitle[size - i - 1])
            answer += (x - 64) * (26 ** i)
        return answer

    def titleToNumber(self, columnTitle: str) -> int:
        answer = 0
        size = len(columnTitle)
        for i, x in enumerate(columnTitle):
            answer += (ord(x) - 64) * (26 ** (size - i - 1))
        return answer

    def titleToNumber(self, columnTitle: str) -> int:
        answer = 0
        for x in columnTitle:
            answer = answer*26 + (ord(x)-64)
        return answer
