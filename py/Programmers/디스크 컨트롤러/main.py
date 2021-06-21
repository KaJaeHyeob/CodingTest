from collections import deque
import heapq


def solution(jobs):
    answer = 0
    cur_time = 0
    sz = len(jobs)
    wait_list = []
    heapq.heapify(wait_list)
    jobs_deque = deque(sorted(jobs, key=lambda x: x[0]))

    while wait_list or jobs_deque:
        while jobs_deque and jobs_deque[0][0] <= cur_time:
            heapq.heappush(wait_list, [jobs_deque[0][1], jobs_deque[0][0]])
            jobs_deque.popleft()
        if wait_list:
            tmp_node = heapq.heappop(wait_list)
            cur_time += tmp_node[0]
            answer += (cur_time - tmp_node[1])
        elif jobs_deque:
            cur_time += (jobs_deque[0][0] - cur_time)

    return answer // sz


