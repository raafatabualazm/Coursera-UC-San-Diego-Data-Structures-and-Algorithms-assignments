# python3
n = input()
W = input()
lst = list()
val = 0
n = int(n)
W = float(W)
for i in range(n):
    v = input()
    w = input()
    v = float(v)
    w = float(w)
    frac = v/w
    newTup = (frac, v, w)
    lst.append(newTup)

lst.sort(reverse=True)

for item in lst:
    if item[2] <= W:
        val = val + item[1]
        W = W - item[2]
    else:
        val = val + (item[0]*W)
        W = 0
    if W == 0:
        break

print(val)
