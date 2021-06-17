for t in range(1, 11):
    res = 0
    n = int(input())
    num_list = list(map(int, input().split()))

    for i in range(2, n - 2):
        ## max() 안에 여러 리스트 넣으면 리스트 간에 비교되므로 하지 말 것
        max_1 = max(max(num_list[i - 2:i]), max(num_list[i + 1:i + 3]))
        max_2 = max(max_1, num_list[i])
        if max_2 > max_1:
            res = res + max_2 - max_1
    print("#{} {}".format(t, res))
