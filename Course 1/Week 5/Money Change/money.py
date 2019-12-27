# python 3
import sys

def minCoins(coinArr, value, table):
    if value <= 0:
        return 0
    else:
        if table.get(value, -1) == -1:
            if coinArr[0] <= value:
                temp1 = minCoins(coinArr, value - coinArr[0], table)
            else:
                temp1 = sys.maxsize
            if coinArr[1] <= value:
                temp2 = minCoins(coinArr, value - coinArr[1], table)
            else:
                temp2 = sys.maxsize
            if coinArr[2]:
                temp3 = minCoins(coinArr, value - coinArr[2], table)
            else:
                temp3 = sys.maxsize
            table[value] = min(temp1, temp2, temp3) + 1

        return table[value]

table = dict()
coinArr = [1, 3, 4]
val = input()
val = int(val)
res = minCoins(coinArr, val, table)
print(res)