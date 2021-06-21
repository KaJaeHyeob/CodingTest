def solution(prices):
    sz = len(prices)
    res_list = [0 for _ in range(sz)]
    my_stack = []

    for i in range(sz):
        while True:
            if my_stack and my_stack[-1][1] > prices[i]:
                res_list[my_stack[-1][0]] = i - my_stack[-1][0]
                my_stack.pop()
            else:
                my_stack.append([i, prices[i]])
                break
    while my_stack:
        res_list[my_stack[-1][0]] = (sz - 1) - my_stack[-1][0]
        my_stack.pop()

    return res_list


