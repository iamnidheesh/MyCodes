x = int(raw_input())
l = [int(i) for i in raw_input().split()]
n = int(raw_input())
earn = 0
for i in range(0,n):
	m = list(map(int,raw_input().split()))
	if m[0] in l:
		earn = earn + m[1]
		l.remove(m[0])
print earn	
