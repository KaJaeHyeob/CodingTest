T = int(input())

xd = [-1, 0, 1, 0]
yd = [0, 1, 0, -1]

for t in range(1, T+1):
    print("#{}".format(t))

    n = int(input())
    x = 0
    y = 0
    xx = 0
    yy = 0
    cnt = 1
    way = 1
    ## 다차원 배열 생성 시 항상 for문 사용할 것 (* 사용 시 링크 복사)
    table01 = [[0 for i in range(n)] for j in range(n)]
    visit01 = [[1 for i in range(n + 2)] for j in range(n + 2)]

    for i in range(1, n+1):
        for j in range(1, n+1):
            visit01[i][j] = 0

    for i in range(0, n**2):
        table01[x][y] = cnt
        visit01[x+1][y+1] = 1

        xx = x+xd[way]
        yy = y+yd[way]
        if visit01[xx+1][yy+1] == 1:
            way = (way+1) % 4

        x = x+xd[way]
        y = y+yd[way]
        cnt = cnt + 1

    for i in range(0, n):
        for j in range(0, n):
            print(table01[i][j], end=" ")
        print()







