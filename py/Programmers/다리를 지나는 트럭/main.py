from collections import deque


def solution(bridge_length, weight, truck_weights):
    cur_time = 0
    cur_weight = 0
    enter_deque = deque()
    weight_deque = deque()
    wait_deque = deque(truck_weights)

    while wait_deque or enter_deque:
        cur_time += 1
        for i in range(len(enter_deque)):
            enter_deque[i] += 1
        if enter_deque and enter_deque[0] > bridge_length:
            cur_weight -= weight_deque[0]
            enter_deque.popleft()
            weight_deque.popleft()
        if wait_deque and cur_weight + wait_deque[0] <= weight:
            cur_weight += wait_deque[0]
            enter_deque.append(1)
            weight_deque.append(wait_deque[0])
            wait_deque.popleft()
        elif enter_deque:
            tmp_add = bridge_length - enter_deque[0]
            cur_time += tmp_add
            for i in range(len(enter_deque)):
                enter_deque[i] += tmp_add

    return cur_time


