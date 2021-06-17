for t in range(1, 11):
    n = int(input())
    h_list = list(map(int, input().split()))
    h_list.sort()

    for i in range(n):
        h_list[0] = h_list[0] + 1
        h_list[99] = h_list[99] - 1
        h_list.sort()

    print("#{} {}".format(t, h_list[99]-h_list[0]))

