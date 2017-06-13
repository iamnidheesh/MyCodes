d={}
for i in range(int(raw_input())):
	line=raw_input().split()
	d[line[0]]=sum(map(float,line[1:]))/3

print '%.2f' % d[raw_input()]

#floats = '3.5 4.2 5.1'  
#floats = map(float, s.split())

