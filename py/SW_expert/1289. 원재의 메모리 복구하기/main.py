tc = int(input())
for t in range(1, tc + 1):
    n = input()
    res = 0
    cur = 0

    for i in range(len(n)):
        if cur != int(n[i]):
            cur = int(n[i])
            res = res + 1

    print("#{} {}".format(t, res))