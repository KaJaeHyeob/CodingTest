def solution(participant, completion):
    ls1 = sorted(list(participant))
    ls2 = sorted(list(completion))
    answer = ls1[-1]
    for i in range(len(ls2)):
        if ls1[i] != ls2[i]:
            answer = ls1[i]
            break
    return answer


