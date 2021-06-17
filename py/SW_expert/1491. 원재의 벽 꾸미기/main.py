tc = int(input())
for t in range(1, tc + 1):
    n, a, b = list(map(int, input().split()))
    res = 10000000000
    for i in range(1, 10000000000):
        if i > n:
            break
        for j in range(1, i + 1):
            if i * j > n:
                break
            tmp = a * (i - j) + b * (n - i * j)
            if res > tmp:
                res = tmp

    print("#{} {}".format(t, res))