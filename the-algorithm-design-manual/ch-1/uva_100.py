import sys
memo = {}


def three(n):
    if n in memo:
        return memo[n]
    if n == 1:
        return 1
    orgin = n
    if n % 2 == 0:
        n = n // 2
    else:
        n = 3 * n + 1
    count = three(n) + 1
    memo[orgin] = count
    return count


def main():
    for line in sys.stdin:
        if not line:
            break
        i, j = [int(x) for x in line.split()]
        if i > j:
            start_point = j
            end_point = i
        else:
            start_point = i
            end_point = j
        maxlength = 0
        for n in range(start_point, end_point + 1):
            maxlength = max(maxlength, three(n))
        print(i, j, maxlength)


if __name__ == '__main__':
    main()
