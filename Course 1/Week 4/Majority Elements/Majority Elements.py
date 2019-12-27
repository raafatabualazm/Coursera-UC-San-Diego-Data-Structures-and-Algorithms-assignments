# python 3
import math


def getFreq(arr, elem):
    sums = 0
    for num in arr:
        if num == elem:
            sums = sums + 1
    return sum


def majorityElement(arr):
    elem1Sum = 0
    elem2Sum = 0

    Length = len(arr)
    HalfL = int(Length/2)
    if Length % 2 == 1:
        arr.sort()
    if Length == 2:
        if arr[0] == arr[1]:
            return arr[0]
        else:
            return -1
    elif Length == 1:
        return arr[0]
    else:
        elem1 = majorityElement(arr[:HalfL])
        elem2 = majorityElement(arr[HalfL:])
    if elem1 == elem2:
        return elem1
    else:
        elem1Sum = sum(1 for num in arr if num == elem1)
        elem2Sum = sum(1 for num in arr if num == elem2)

    if elem1Sum > HalfL:
        return elem1
    elif elem2Sum > HalfL:
        return elem2
    else:
        return -1


n = input()
array = input()
array = array.split()
for i in range(len(array)):
    array[i] = int(array[i])

ans = majorityElement(array)

if ans > -1:
    print(1)
else:
    print(0)