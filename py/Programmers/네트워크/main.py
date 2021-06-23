def solution(n, computers):
    answer = 0
    computers = [[i for i, j in enumerate(item) if j == 1] for item in computers]
    visited_list = [0 for _ in range(n)]

    ## BFS 함수 (큐 또는 스택)
    def bfs(num):
        my_stack = [num]
        while my_stack:
            tmp_num = my_stack.pop()
            visited_list[tmp_num] = 1
            for i in computers[tmp_num]:
                if visited_list[i] == 0:
                    my_stack.append(i)
        return 0

    ## DFS 함수 (재귀)
    def dfs(num):
        visited_list[num] = 1
        for i in computers[num]:
            if visited_list[i] == 0:
                dfs(i)
        return 0

    for item in computers:
        for num in item:
            if visited_list[num] == 0:
                answer += 1
                dfs(num)
                break

    return answer


'''
def solution(n, computers):
    computers = [set([i for i, j in enumerate(item) if j == 1]) for item in computers]

    while True:
        is_doing = -1
        for i in range(len(computers)):
            for j in range(i + 1, len(computers)):
                for k in range(len(computers[i])):
                    if list(computers[i])[k] in computers[j]:
                        computers[i] |= computers[j]
                        del computers[j]
                        is_doing = 1
        if is_doing == -1:
            break

    return len(computers)
'''


