#python 3


def solve(N, W, Wt):
    dpw = [[0 for x in range(W+1)] for y in range(N+1)]
    for n in range(N+1):
        for w in range(W+1):
            if n == 0 or w == 0:
                dpw[n][w] = 0
            elif w < Wt[n]:
                dpw[n][w] = dpw[n - 1][w]
            else:
                dpw[n][w] = max(dpw[n - 1][w], Wt[n] + dpw[n - 1][w - Wt[n]])
    return dpw[n][w]


inp = input().split()
W = int(inp[0])
N = int(inp[1])
Wt = [0]
x = input()
x = x.split()
for elem in x:
    Wt.append(int(elem))
ans = solve(N, W, Wt)
print(ans)