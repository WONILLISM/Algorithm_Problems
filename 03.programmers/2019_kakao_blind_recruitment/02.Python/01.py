def solution(record):
    answer = []
    m = {}
    printer = {'Enter':'님이 들어왔습니다.', 'Leave':'님이 나갔습니다.'}
    for r in record:
        tmp = r.split(' ')
        if tmp[0] in ['Enter', 'Change']:
            m[tmp[1]] = tmp[2]

    for r in record:
        if r.split(' ')[0] != 'Change':
            answer.append(m[r.split(' ')[1]] + printer[r.split(' ')[0]])

    return answer

input_record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
print(solution(input_record))