def recur(s, cnt, depth):
    if s == '1':
        return [depth, cnt]
    cnt_tmp = s.count('0')
    s_tmp = s.replace("0","")
    s_tmp_len = len(s_tmp)
    bi = format(s_tmp_len, 'b')
    return recur(str(bi), cnt + cnt_tmp, depth + 1)
    
def solution(s):
    return recur(s, 0, 0)