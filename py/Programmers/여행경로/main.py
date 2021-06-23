cnt = 0


def solution(tickets):
    answer = ["ICN"]
    sz = len(tickets)
    tickets.sort(key=lambda x: x[1])
    used_list = [0 for _ in range(sz)]
    global cnt

    def dfs(begin):
        global cnt
        if cnt == sz:
            return 1
        for i, j in enumerate(tickets):
            if j[0] == begin and used_list[i] == 0:
                used_list[i] = 1
                cnt += 1
                answer.append(j[1])
                dfs(j[1])
                if cnt == sz:
                    return 1
                answer.pop()
                cnt -= 1
                used_list[i] = 0

    dfs("ICN")

    return answer


