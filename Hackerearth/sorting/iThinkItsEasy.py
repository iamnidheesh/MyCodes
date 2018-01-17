n = int(input())
for i in range(n) :
	s = input().split()
	s = [(k,len(k)) for k in s]
	s = sorted(s ,key = lambda x : x[1])
	for k in s :
		print(k[0],end = ' ')
	print()