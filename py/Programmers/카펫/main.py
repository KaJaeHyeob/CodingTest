def solution(brown, yellow):
    answer = []
    tmp_div = int(yellow ** 0.5)

    for i in range(1, tmp_div + 1):
        if yellow % i == 0 and (i + 2) * ((yellow // i) + 2) == brown + yellow:
            answer = [(yellow // i) + 2, i + 2]
            break

    return answer


