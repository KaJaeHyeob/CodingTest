import collections

tc = 10
for t in range(1,tc+1):
    cz, n = input().split()
    cz = int(cz)
    myQ = collections.deque()
    myQ.append(n[0])
    for c in range(1,cz):
        if len(myQ) == 0:
            myQ.append(n[c])
            continue
        if myQ[len(myQ)-1] == n[c]:
            myQ.pop()
        else:
            myQ.append(n[c])
    res = "".join(myQ)
    print("#{} {}".format(t, res))




