from collections import deque


def solution(progresses, speeds):
    answer = []

    myDeque = deque(progresses)
    speed_deque = deque(speeds)
    while myDeque:
        tmp_cnt = 0
        while myDeque and myDeque[0] >= 100:
            tmp_cnt += 1
            myDeque.popleft()
            speed_deque.popleft()
        if tmp_cnt > 0:
            answer.append(tmp_cnt)
        for i in range(len(myDeque)):
            myDeque[i] += speed_deque[i]

    return answer


