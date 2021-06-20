import collections

tc = 10
for t in range(1, tc+1):
    no_use = input()
    num_list = list(map(int, input().split()))
    min_num = min(num_list)
    max_num = max(num_list)
    cnt = 0
    if max_num % 15 < 10:
        cnt = (max_num // 15) - 1
        if cnt < 0:
            cnt = 0
    else:
        cnt = max_num // 15
    num_deque = collections.deque([i - (cnt*15) for i in num_list])

    cur = 1
    while True:
        tmp = num_deque.popleft()
        num_deque.append(tmp-cur)
        cur = (cur % 5) + 1
        if num_deque[7] <= 0:
            num_deque[7] = 0
            break

    res_list = list(map(str, num_deque))
    ## str.join() 파라미터는 str list 타입만 허용
    res = " ".join(res_list)
    print("#{} {}".format(t, res))


