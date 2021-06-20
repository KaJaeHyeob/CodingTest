def solution(phone_book):
    answer = True
    myL = sorted(phone_book)
    sz = len(myL)
    for i in range(0, sz-1):
        if len(myL[i]) < len(myL[i+1]):
            if myL[i] == myL[i+1][:len(myL[i])]:
                answer = False
                break
    return answer


