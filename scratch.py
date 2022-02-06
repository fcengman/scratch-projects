import random as r
import timeit


def poly(x, p):

    total = p[0]
    for i in range(1, len(p)):
        total += p[i] * (x**i)

    return total


def rpoly(x, p):
    total = p[0] + (p[1] * x)
    power = x
    for i in range(2, len(p)):
        power = x * power
        total += p[i] * power

    return total


def npoly(x, p):
    n = len(p) - 1
    total = p[len(p)-1]
    i = n-1
    while i >= 0:
        total = p[i] + (x * total)
        i -= 1

    return total


def main():
    x = 1
    size = 20000000
    p = []
    for i in range(size):
        p.append(r.choice([-10, -9, -8, -7, -6, -5, -
                           4, -3, -2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))

    start = timeit.default_timer()

    # Your statements here
    print(poly(x, p))

    stop = timeit.default_timer()

    print('Brute Force Time: ', stop - start)
    start = timeit.default_timer()

    # Your statements here
    print(rpoly(x, p))

    stop = timeit.default_timer()

    print('Recursive Time: ', stop - start)

    start = timeit.default_timer()

    # Your statements here
    print(npoly(x, p))

    stop = timeit.default_timer()

    print('Nested Time: ', stop - start)


if __name__ == '__main__':
    main()
