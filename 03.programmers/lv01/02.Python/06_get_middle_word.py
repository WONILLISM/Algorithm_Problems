def solution(s):
    return  s[len(s)//2] if len(s) & 1 else s[len(s)//2 -1 : len(s)//2 +1]

# def solution(s):
#      return s[(len(s)-1)//2:len(s)//2+1]