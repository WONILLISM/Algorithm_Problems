def solution(skill, skill_trees):
    answer = 0

    for skills in skill_trees:
        skill_list = list(skill)

        for s in skills:
            if s in skill:
                if s != skill_list.pop(0):
                    break
        else:
            answer += 1

    return answer


input_skill = "CBD"
input_skill_tree = ["BACDE", "CBADF", "AECB", "BDA"]
print(solution(input_skill,input_skill_tree))