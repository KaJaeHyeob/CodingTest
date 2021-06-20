tc = 10
str_list = []
find_num = 0
res = 0


def cal_tomato(i, j, k):
    for x in range(0, (k//2)+1):
        if str_list[i][j+x] != str_list[i][j+k-1-x]:
            return -1
    global res
    res = res+1
    return 1


def cal_tomato_2(i, j, k):
    for x in range(0, (k//2)+1):
        if str_list[j+x][i] != str_list[j+k-1-x][i]:
            return -1
    global res
    res = res + 1
    return 1


for t in range(1, tc+1):
    find_num = int(input())
    str_list = ["" for _ in range(8)]
    for i in range(8):
        str_list[i] = input()

    res = 0
    for i in range(8):
        for j in range(8):
            if j+find_num-1 > 7:
                break
            cal_tomato(i, j, find_num)
            cal_tomato_2(i, j, find_num)
    print("#{} {}".format(t, res))

