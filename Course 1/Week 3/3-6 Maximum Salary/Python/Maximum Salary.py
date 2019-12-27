# python 3

import functools


def sortAlg(num1, num2):
    num3 = num1 + num2
    num4 = num2 + num1
    return (int(num3) > int(num4)) - (int(num4) > int(num3))


n = input()
n = int(n)
numbers = input()
numbers2 = numbers.split()
numbers2.sort(key=functools.cmp_to_key(sortAlg))
numbers2.reverse()
for num in numbers2:
    print(num, end='')

