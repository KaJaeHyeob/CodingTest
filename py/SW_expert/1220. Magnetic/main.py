import collections

szN = 100

tc = 10
for t in range(1, tc + 1):
    ign = input()
    num_tab = []
    for i in range(szN):
        num_list = list(map(int, input().split()))
        num_tab.append(num_list)

    res = 0

    for j in range(szN):
        myQ = collections.deque()
        for i in range(szN):
            if num_tab[i][j] == 1:
                if len(myQ) == 0:
                    myQ.append(1)
                else:
                    if myQ[len(myQ) - 1] == 2:
                        myQ.append(1)
            elif num_tab[i][j] == 2:
                if len(myQ) == 0:
                    myQ.append(2)
                else:
                    if myQ[len(myQ) - 1] == 1:
                        myQ.append(2)

        while myQ:
            if myQ[len(myQ) - 1] == 1:
                myQ.pop()
            else:
                break
        while myQ:
            if myQ[0] == 2:
                myQ.popleft()
            else:
                break

        res = res + myQ.count(1)

    print("#{} {}".format(t, res))
