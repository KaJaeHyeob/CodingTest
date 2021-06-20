from collections import deque


def solution(priorities, location):
    answer = 0
    real_pri = priorities
    sorted_pri = deque(sorted(priorities, reverse=True))
    sz = len(sorted_pri)
    i = 0
    while True:
        if real_pri[i] == sorted_pri[0]:
            answer += 1
            real_pri[i] = -1
            sorted_pri.popleft()
            if i == location:
                break
        i = (i+1)%sz
    return answer

