from collections import deque


def solution(numbers, target):
    my_list = deque([0])

    for item in numbers:
        sz = len(my_list)
        for i in range(sz):
            tmp_num = my_list.popleft()
            my_list.extend([tmp_num - item, tmp_num + item])

    return my_list.count(target)


