import heapq


def solution(scoville, K):
    answer = 0
    ## list 최소힙 정렬 (전체 정렬 아닌 것에 주의할 것)
    ## max, min 반복적으로 찾을 떄 유용
    heapq.heapify(scoville)

    while True:
        if scoville[0] >= K:
            break
        if len(scoville) == 1:
            answer = -1
            break
        answer += 1
        ## list pop 후에 최소힙 정렬
        tmp_mix = heapq.heappop(scoville) + 2 * heapq.heappop(scoville)
        ## list push 후에 최소힙 정렬
        heapq.heappush(scoville, tmp_mix)

    return answer


