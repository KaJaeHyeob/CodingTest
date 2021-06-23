from collections import deque

answer = 0


def solution(begin, target, words):
    global answer
    if target not in words:
        return 0
    words.append(begin)
    sz = len(words)
    visited_list = [0 for _ in range(sz)]

    def bfs(begin_str):
        global answer
        my_q = deque([begin_str])
        visited_list[words.index(begin_str)] = 1
        while my_q:
            answer += 1
            if answer > sz:
                return -1
            tmp_sz = len(my_q)
            for _ in range(tmp_sz):
                tmp_str = my_q.popleft()
                for i, j in enumerate(words):
                    if visited_list[i] == 0:
                        tmp_cnt = 0
                        for k in range(len(j)):
                            if tmp_str[k] != j[k]:
                                tmp_cnt += 1
                                if tmp_cnt >= 2:
                                    break
                        if tmp_cnt == 1:
                            my_q.append(j)
                            if j == target:
                                return 1
                            visited_list[i] = 1

    tmp_res = bfs(begin)
    if tmp_res == -1:
        return 0
    else:
        return answer


