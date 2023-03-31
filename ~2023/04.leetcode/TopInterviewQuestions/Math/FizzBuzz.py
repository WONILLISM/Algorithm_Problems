from typing import List

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        answer = list()
        for i in range(n):
            j = i + 1
            if j % 3 == 0 and j % 5 == 0:
                answer.append("FizzBuzz")
            elif j % 3 == 0:
                answer.append("Fizz")
            elif j % 5 == 0:
                answer.append("Buzz")
            else:
                answer.append(str(j))
        return answer

    def fizzBuzz(self, n: int) -> List[str]:
        answer=[]
        for i in range(1, n+1):
            if i%15==0:
                answer.append("FizzBuzz")
            elif i%3==0:
                answer.append("Fizz")
            elif i%5==0:
                answer.append("Buzz")
            else:
                answer.append(str(i))
        return answer
