from itertools import permutations


def is_sosu(n):
    if n in [0, 1]:
        return -1
    if n <= 3:
        return 1
    tmp_div = int(n ** 0.5)
    for i in range(2, tmp_div + 1):
        if n % i == 0:
            return -1
    return 1


def solution(numbers):
    answer = 0
    num_list = []

    char_list = [i for i in numbers]
    for i in range(1, len(char_list) + 1):
        num_list.extend(list(permutations(char_list, i)))
    num_list = [int("".join(i)) for i in num_list]
    num_list = list(set(num_list))
    print(num_list)

    for i in num_list:
        if is_sosu(i) == 1:
            answer += 1

    return answer


'''
## 에라토스테네스의 체 사용하는 방법
def solution(n):
    a = set()
    for i in range(len(n)):
        a |= set(map(int, map("".join, permutations(list(n), i + 1))))
    a -= set(range(0, 2))
    for i in range(2, int(max(a) ** 0.5) + 1):
        a -= set(range(i * 2, max(a) + 1, i))
    return len(a)
'''