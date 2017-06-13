from itertools import combinations
x = raw_input().split()
for i in range(1,int(x[1]) + 1):
	for j in list(combinations(sorted(x[0]),i)):
		print "".join(j)

