class Solution:
    def romanToInt(self, s: str) -> int:
        chardict={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        n=len(s)
        answer = chardict[s[n-1]]
        for i in range(n-1,0,-1):
            p,c=chardict[s[i-1]],chardict[s[i]]
            answer += p if p>=c else -p
        return answer

    def romanToInt(self, s: str) -> int:
        chardict={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        answer = chardict[s[0]]
        for i in range(1,len(s)):
            p,c=chardict[s[i-1]],chardict[s[i]]
            if p<c:
                answer+=c-p*2
            else:
                answer+=c
        return answer
