tc = 10
str_list = []


def cal_tomato(i, j, k):
    for x in range(0, ((k-j)//2)+1):
        if str_list[i][j+x] != str_list[i][k-x]:
            return -1
    return 1


def cal_tomato_2(i, j, k):
    for x in range(0, ((k-j)//2)+1):
        if str_list[j+x][i] != str_list[k-x][i]:
            return -1
    return 1


for t in range(1, tc+1):
    ign = input()
    str_list = ["" for _ in range(100)]
    for i in range(100):
        str_list[i] = input()

    res = 1
    for i in range(100):
        for j in range(100):
            for k in range(99, j, -1):
                if k-j+1 <= res:
                    break
                if cal_tomato(i, j, k) == 1 or cal_tomato_2(i, j, k) == 1:
                    res = k-j+1
                    break
    print("#{} {}".format(t, res))



