# python 3
import sys
def primitiveCalc(value, table, currentIt, maxIt):
    if currentIt >= maxIt:
        return sys.maxsize, []
    out = []
    outTemp1 = []
    outTemp2 = []
    outTemp3 = []
    temp1 = sys.maxsize - 10
    temp2 = sys.maxsize - 10
    temp3 = sys.maxsize - 10
    out.append(value)
    if value <= 1:
        return 0, out
    else:
        if table.get(value, -1) == -1:
            if value % 3 == 0:
                temp1, outTemp1 = primitiveCalc(int(value/3), table, 0, sys.maxsize)
            if value % 2 == 0:
                temp2, outTemp2 = primitiveCalc(int(value/2), table, 0, sys.maxsize)
            temp4 = min(temp1, temp2)
            currentIt = currentIt + 1
            temp3, outTemp3 = primitiveCalc(value - 1, table, currentIt, temp4)
            res = min(temp1, temp2, temp3) + 1
            if res -1 == temp1:
                out += outTemp1
            elif res -1 == temp2:
                out += outTemp2
            elif res - 1 == temp3:
                out += outTemp3
            table[value] = res, out

        return table[value]



table = dict()
val = input()
val = int(val)
res, seq = primitiveCalc(val, table, 0, sys.maxsize)
print(res)
seq = reversed(seq)
for item in seq:
    print(item, end=" ")