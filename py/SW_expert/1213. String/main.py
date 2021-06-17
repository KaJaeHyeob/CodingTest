for t in range(1,11):
    tr = input()
    print("#{}".format(t), end=" ")
    short_str = input()
    long_str = input()

    cnt = long_str.count(short_str)
    print(cnt)