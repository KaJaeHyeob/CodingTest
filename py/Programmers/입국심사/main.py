def solution(n, times):
    times.sort()

    min_n = 0
    max_n = times[-1] * n
    mid_n = int((min_n + max_n) / 2)

    while True:
        tmp_sum = sum([mid_n // item for item in times])
        if tmp_sum >= n:
            max_n = mid_n
            mid_n = int((min_n + max_n) / 2)
        else:
            min_n = mid_n
            mid_n = int((min_n + max_n) / 2)
        if min_n == mid_n:
            break

    return max_n


