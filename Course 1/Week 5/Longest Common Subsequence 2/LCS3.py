#python 3
def computeLCS(a, b, c):
    LCSmap = [[[0 for i in range(len(c)+1)] for i in range(len(b)+1)] for i in range(len(a)+1)]
    for i in range(len(a) +1):
        for j in range(len(b)+1):
            for k in range(len(c) +1):
                if i == 0 or j == 0 or k == 0:
                    LCSmap[i][j][k] = 0
                elif a[i-1] == b[j-1] and b[j-1] == c[k-1]:
                    LCSmap[i][j][k] = LCSmap[i-1][j-1][k-1] + 1
                else:
                    LCSmap[i][j][k] = max(LCSmap[i-1][j][k], LCSmap[i][j-1][k], LCSmap[i][j][k-1])
    return LCSmap[len(a)][len(b)][len(c)]


al = []
bl = []
cl = []

a = input()
y = input()
al = y.split()

b = input()
z = input()
bl = z.split()

c = input()
w = input()
cl = w.split()

ans = computeLCS(al, bl, cl)
print(ans)