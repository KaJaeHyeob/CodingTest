import collections

tc = int(input())
for t in range(1, tc+1):
    nStr, cStr = input().split()
    n = int(nStr)
    c = int(cStr)
    myQueue = collections.deque([n])
    szN = len(str(nStr))
    for ch in range(0, c):
        ## set은 순서가 없다
        ## 항상 list를 사용하고 중복 없앨 때만 set 거쳐오기
        mySet = set(myQueue)
        myQueue = collections.deque(mySet)
        szQueue = len(myQueue)
        for sz in range(szQueue):
            ## str을 int로 바꿀 때 앞에 0 사라진다는 것을 주의할 것
            toNewNum = list(str(myQueue.popleft()).rjust(szN, "0"))
            for i in range(1, szN):
                for j in range(0, i):
                    ## 복사할 때 항상 함수 사용해서 할 것 (안 하면 링크 복사)
                    cp_toNewNum = list(toNewNum)
                    tmp = cp_toNewNum[i]
                    cp_toNewNum[i] = cp_toNewNum[j]
                    cp_toNewNum[j] = tmp
                    ## list를 str로 바꾸는 방법
                    myQueue.append(int("".join(cp_toNewNum)))
    print("#{} {}".format(t, max(myQueue)))
