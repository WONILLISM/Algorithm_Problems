chk=[]
s = set()
def process(user_id, banned_id, res, idx):
    if idx == len(banned_id):
        res = sorted(res)
        global s
        s.add(res)
    
    bid = banned_id[idx]

    for i  in range(len(user_id)):
        uid = user_id[i]
        if len(uid) == len(bid) and chk[i]==False:
            flag=True
            for j in range(len(bid)):
                if bid[j]!='*' and bid[j]!=uid[j]:
                    flag = False
                    break

            if flag:
                chk[i]=True
                process(user_id,banned_id,res + str(i), idx+1)
                chk[i]=False

def solution(user_id, banned_id):
    answer = 0
    global chk
    for i in user_id:
        chk.append(False)

    process(user_id,banned_id,"",0)
    answer = len(s)    

    return answer



input_uid = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
input_bid = ["fr*d*", "abc1**"]

# input_uid = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
# input_bid = ["*rodo", "*rodo", "******"]

# input_uid = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
# input_bid = ["fr*d*", "*rodo", "******", "******"]

print(solution(input_uid, input_bid))