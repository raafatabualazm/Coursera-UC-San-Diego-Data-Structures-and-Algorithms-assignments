# python 3
def partition3(arr, starti, endi):
    pivot = arr[endi-1]
    pIndex = endi-1
    lessInex = starti
    i = starti
    while i <= pIndex:
        if arr[i] < pivot:
            lessInex += 1
            arr[i], arr[lessInex - 1] = arr[lessInex - 1], arr[i]
            i += 1
        elif arr[i] > pivot:
            pIndex -= 1
            arr[i], arr[pIndex + 1] = arr[pIndex + 1], arr[i]
        else:
            i += 1

    return pIndex, lessInex


def Quick3Sort(arr, starti, endi):
    if starti >= endi:
        return
    pIndex, lessIndex = partition3(arr, starti, endi)
    Quick3Sort(arr, starti, lessIndex)
    Quick3Sort(arr, pIndex+1, endi)


n = input()
arr = input()
arr = arr.split()
n = int(n)
for i in range(n):
    arr[i] = int(arr[i])
Quick3Sort(arr, 0, n)
for num in arr:
    print(num, end=" ")




