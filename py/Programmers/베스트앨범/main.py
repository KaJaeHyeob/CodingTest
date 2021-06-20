def solution(genres, plays):
    answer = []
    idx_dict = dict()
    sum_dict = dict()
    max_list = []
    max2_list = []
    sz = len(genres)
    cur_idx = 0
    for i in range(sz):
        if genres[i] not in idx_dict.keys():
            idx_dict[genres[i]] = cur_idx
            sum_dict[genres[i]] = plays[i]
            max_list.append((plays[i], i))
            max2_list.append((0, -1))
            cur_idx += 1
        else:
            sum_dict[genres[i]] += plays[i]
            tmp_idx = idx_dict[genres[i]]
            if max_list[tmp_idx][0] < plays[i]:
                max2_list[tmp_idx] = max_list[tmp_idx]
                max_list[tmp_idx] = (plays[i], i)
            elif max2_list[tmp_idx][0] < plays[i]:
                max2_list[tmp_idx] = (plays[i], i)

    ## dict 정렬 list 반환
    sorted_sum_dict_list = sorted(sum_dict.items(), key=lambda x:x[1], reverse=True)
    '''
    ## list dict 변환
    test_dict = {i:j for i,j in sorted_sum_dict_list}
    ## value 사용해 key 찾는 방법으로 뒤집은 dict 종종 사용
    inv_sum_dict = {i: j for j, i in sum_dict.items()}
    '''
    sz2 = len(sorted_sum_dict_list)
    for i in range(sz2):
        tmp_idx = idx_dict[sorted_sum_dict_list[i][0]]
        answer.append(max_list[tmp_idx][1])
        if max2_list[tmp_idx][1] != -1:
            answer.append(max2_list[tmp_idx][1])

    return answer

