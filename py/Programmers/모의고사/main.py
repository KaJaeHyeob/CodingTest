def solution(answers):
    answer = [[i, 0] for i in range(1, 4)]
    ls = [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]

    for i, item in enumerate(answers):
        for j in range(3):
            if item == ls[j][i % len(ls[j])]:
                answer[j][1] += 1
    answer.sort(key=lambda x: (-x[1], x[0]))
    tmp_max = answer[0][1]
    for i in range(3):
        if tmp_max != answer[i][1]:
            answer = answer[:i]
            break
    answer = [item[0] for item in answer]

    return answer


