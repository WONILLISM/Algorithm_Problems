def solution(w,h):
    get_GCD = lambda a, b : b if a%b==0 else get_GCD(b,a%b)
    GCD = get_GCD(w,h)
    return w*h - (w + h - GCD)