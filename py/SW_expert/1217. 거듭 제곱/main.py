def zzz(a, b, ini):
    if b == 1:
        return a
    else:
        return zzz(a * ini, b - 1, ini)


tc = 10
for t in range(1, tc + 1):
    ign = input()
    a, b = list(map(int, input().split()))
    res = zzz(a, b, a)
    print("#{} {}".format(t, res))
