def solution(numbers):
    answer = ''
    myList = []
    for item in numbers:
        if item < 10:
            myList.append([str(item) * 4, 1])
        elif item < 100:
            myList.append([str(item) * 2, 2])
        elif item < 1000:
            myList.append([str(item) + str(item)[0], 3])
        elif item == 1000:
            myList.append([str(1000), 4])
    myList.sort(reverse=True)
    myList2 = [i[:j] for i, j in myList]
    answer = "".join(myList2)
    if int(answer) == 0:
        answer = "0"

    return answer


