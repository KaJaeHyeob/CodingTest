for t in range(1, 11):
    tr = input()
    num_table = []
    max_sum = 0

    for i in range(100):
        num_list = list(map(int, input().split()))
        num_table.append(num_list)

    for i in range(100):
        temp_sum1 = 0
        temp_sum2 = 0
        for j in range(100):
            temp_sum1 = temp_sum1 + num_table[i][j]
            temp_sum2 = temp_sum2 + num_table[j][i]
        max_sum = max(temp_sum1, temp_sum2, max_sum)

    temp_sum3 = 0
    temp_sum4 = 0
    for i in range(100):
        temp_sum3 = temp_sum3 + num_table[i][i]
        temp_sum4 = temp_sum4 + num_table[99-i][i]
    max_sum = max(temp_sum3, temp_sum4, max_sum)

    print("#{} {}".format(t, max_sum))