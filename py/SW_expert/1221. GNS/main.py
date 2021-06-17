tc = int(input())
n_code = ["ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"]
for t in range(1, tc + 1):
    ign, szN = input().split()
    szN = int(szN)
    n_list = input().split()
    res_list = [0 for _ in range(10)]

    for i in range(szN):
        tmp_index = n_code.index(n_list[i])
        res_list[tmp_index] = res_list[tmp_index] + 1

    res = [(n_code[i] + " ") * j for i, j in enumerate(res_list) if j != 0]
    res = "".join(res)
    print("#{}".format(t))
    print("{}".format(res))