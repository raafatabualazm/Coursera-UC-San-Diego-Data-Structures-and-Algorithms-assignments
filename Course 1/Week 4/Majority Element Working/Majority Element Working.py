# python 3
n = input()
flag = False
freq = dict()
array = input()
array = array.split()
for i in range(len(array)):
    freq[array[i]] = freq.get(array[i], 0) + 1

for v, k in freq.items():
    if k > int(len(array)/2):
        flag = True

if flag == True:
    print(1)
else:
    print(0)