def solution(clothes):
    myDict = dict()
    for i in range(len(clothes)):
        if clothes[i][1] not in myDict.keys():
            myDict[clothes[i][1]] = 1
        else:
            myDict[clothes[i][1]] += 1
    answer = 1
    for i in myDict.values():
        answer *= (i+1)
    return (answer-1)