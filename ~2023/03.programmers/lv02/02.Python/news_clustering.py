def solution(str1, str2):
    MUL = 65536
    str1 = [str1[i:i+2].lower() for i in range(0,len(str1)-1) if str1[i:i+2].isalpha()]
    str2 = [str2[i:i+2].lower() for i in range(0,len(str2)-1) if str2[i:i+2].isalpha()]
    if len(str1)==0 and len(str2)==0: return MUL
    
    union = sum([max(str1.count(u), str2.count(u)) for u in set(str1) | set(str2)])
    intersec = sum([min(str1.count(i), str2.count(i)) for i in set(str1) & set(str2)])
    
    return int(intersec/union*MUL)

# input_str1 = "FRANCE"
# input_str2 = "french"
input_str1 = "aa1+aa2"
input_str2 = "AAAA12"
print(solution(input_str1, input_str2))
#solution(input_str1, input_str2)