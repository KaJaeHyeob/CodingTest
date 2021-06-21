def solution(array, commands):
    answer = []

    for item in commands:
        myList = list(array)
        answer.append(sorted(myList[item[0] - 1:item[1]])[item[2] - 1])

    return answer


