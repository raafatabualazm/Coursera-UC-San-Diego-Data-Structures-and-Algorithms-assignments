# python 3
def getMinMax(maxVals, minVals,i, j, op):
    maxVal = -9999999999999999999999
    minVal = 9999999999999999999999
    for k in range(i,j):
        oper = op[k]
        if oper == '+':
            a = minVals[i][k] + minVals[k+1][j]
            b = minVals[i][k] + maxVals[k+1][j]
            c = maxVals[i][k] + maxVals[k+1][j]
            d = maxVals[i][k] + minVals[k+1][j]
        elif oper == '-':
            a = minVals[i][k] - minVals[k + 1][j]
            b = minVals[i][k] - maxVals[k + 1][j]
            c = maxVals[i][k] - maxVals[k + 1][j]
            d = maxVals[i][k] - minVals[k + 1][j]
        elif oper == '*':
            a = minVals[i][k] * minVals[k + 1][j]
            b = minVals[i][k] * maxVals[k + 1][j]
            c = maxVals[i][k] * maxVals[k + 1][j]
            d = maxVals[i][k] * minVals[k + 1][j]
        maxVal = max(a, b, c, d, maxVal)
        minVal = min(a, b, c, d, minVal)
    return maxVal, minVal

def solve(maxVals, minVals, op):
    for s in range(1, len(nums)):
        for i in range(len(nums) - s):
            j = i + s
            maxVals[i][j], minVals[i][j] = getMinMax(maxVals, minVals, i, j, op)
    return maxVals[0][len(nums) -1]

inp = input()
nums = []
ops = []
for num in inp:
    if num.isdigit():
        nums.append(int(num))
    else:
        ops.append(num)

maxVals = [[None for x in range(len(nums))] for y in range(len(nums))]
minVals = [[None for x in range(len(nums))] for y in range(len(nums))]

for i in range(len(nums)):
    maxVals[i][i] = nums[i]
    minVals[i][i] = nums[i]

ans = solve(maxVals, minVals, ops)
print(ans)