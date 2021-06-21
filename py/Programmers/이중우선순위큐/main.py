import heapq


def solution(operations):
    answer = []
    myHeap = []
    heapq.heapify(myHeap)

    for item in operations:
        op, num = item.split()
        num = int(num)
        if op == "I":
            heapq.heappush(myHeap, num)
        elif myHeap and num == -1:
            heapq.heappop(myHeap)
        elif myHeap and num == 1:
            myHeap = heapq.nlargest(len(myHeap), myHeap)[1:]
            heapq.heapify(myHeap)
        print(myHeap)
    if myHeap:
        answer.append(heapq.nlargest(1, myHeap)[0])
        answer.append(heapq.heappop(myHeap))
    else:
        answer.extend([0, 0])

    return answer


