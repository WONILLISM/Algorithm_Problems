def solution(files):
    dic = dict()
    for file in files:
        h, n = None, None
        for i in range(len(file)):
            if file[i].isnumeric(): break
            else: h = i
        for i in range(h+1, len(file)):
            if file[i].isnumeric(): n = i
            else: break
        head, number = file[:h+1].lower(), int(file[h+1:n+1])
        dic[file] = (head, number)
    answer = [file_name for file_name, file_info in sorted(dic.items(), key=lambda x: (x[1][0], x[1][1]))]
    return answer


input_files = ["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]
print(solution(input_files))