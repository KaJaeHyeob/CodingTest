import collections

tc = 10
for t in range(1, tc+1):
    sz_code = int(input())
    myQ = collections.deque(input().split())
    sz_command = int(input())
    myCommand = collections.deque(input().split())
    while myCommand:
        command = myCommand.popleft()
        if command == "I":
            idx = int(myCommand.popleft())
            cnt = int(myCommand.popleft())
            for c in range(cnt):
                tmp = myCommand.popleft()
                myQ.insert(idx, tmp)
                idx = idx + 1
        elif command == "D":
            idx = int(myCommand.popleft())
            cnt = int(myCommand.popleft())
            for c in range(cnt):
                ## deque.pop() 인덱싱 파라미터 사용 불가능하기 때문에 del 사용
                del myQ[idx]
        else:
            cnt = int(myCommand.popleft())
            for c in range(cnt):
                tmp = myCommand.popleft()
                myQ.append(tmp)
    ## deque는 슬라이싱이 불가능하기 때문에 list로 변환
    myL = list(myQ)
    res = " ".join(myL[0:10])
    print("#{} {}".format(t, res))





