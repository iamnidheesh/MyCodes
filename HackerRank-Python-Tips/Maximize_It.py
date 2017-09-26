from itertools import product
km = raw_input().split()
p = []
for i in range(0,int(km[0])):
	p.append(list(map(int,raw_input().split()[1:])))
l = list(product(*p))
ans = []
for i in l:
	k = 0
	for j in i:
		k = k + (j*j)%int(km[1])
	k = k%int(km[1])
	ans.append(k)
print max(ans)

		

