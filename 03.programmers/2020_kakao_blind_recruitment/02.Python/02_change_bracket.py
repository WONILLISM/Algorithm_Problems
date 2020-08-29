def solution(p):
    # 1
    if p == '':
        return p
    is_right_brck = True
    c = 0
    # 2
    for i in range(len(p)):
        if p[i] == '(': c -= 1
        else : c += 1
        if c > 0: is_right_brck = False
        if c == 0 :
            if is_right_brck :
                return p[:i + 1] + solution(p[i + 1:])
            else :
                return '(' + solution(p[i + 1 :]) + ')' + ''.join(list(map(lambda x: '(' if x==')' else ')', p[1:i]) )) 