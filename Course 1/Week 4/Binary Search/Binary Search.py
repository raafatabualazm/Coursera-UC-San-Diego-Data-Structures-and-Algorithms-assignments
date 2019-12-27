# python 3
import math


def BinarySearch(c, d, left, right) -> int:
    m = (left + right)/2
    m = math.floor(m)
    m = int(m)
    right2 = right
    left2 = left
    if c == d[m]:
        return m
    elif c < d[m]:
        right2 = m - 1
    elif c > d[m]:
        left2 = m + 1

    if right2 < left or left2 > right:
        return -1
    else:
        return BinarySearch(c, d, left2, right2)


ans = list()
a = input()
b = input()
a = a.split()
b = b.split()
for i in range(len(a)):
    a[i] = int(a[i])
for j in range(len(b)):
    b[j] = int(b[j])
a.pop(0)
b.pop(0)
for num in b:
    an = BinarySearch(num, a, 0, len(a)-1)
    ans.append(an)


for an2 in ans:
    print(an2, end=" ")
