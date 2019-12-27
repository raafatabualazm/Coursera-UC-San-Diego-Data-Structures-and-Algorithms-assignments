# python 3
def solve(N, Sum, Nums):
    dpw = [[False for x in range(Sum + 1)] for y in range(N + 1)]
    for k in range(N+1):
        dpw[k][0] = True
    for k in range(1, Sum+1):
        dpw[0][k] = False
    for n in range(1, N+1):
        for s in range(1, Sum + 1):
            if s < Nums[n]:
                dpw[n][s] = dpw[n - 1][s]
            else:
                dpw[n][s] = dpw[n - 1][s] or dpw[n - 1][s - Nums[n]]
    return dpw[n][s]


n = int(input())
inp = input().split()
nums = [0]
for element in inp:
    nums.append(int(element))

num_sum = sum(nums)
if n < 3 or num_sum % 3 != 0:
    print(0)
else:
    ans = solve(n, int(num_sum/3), nums)
    if ans == True:
        print(1)
    else:
        print(0)

