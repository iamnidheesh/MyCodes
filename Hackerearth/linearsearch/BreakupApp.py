n = int(input())
d = {}
l = []
for i in range(n) :
	s = input().split()
	wt = 1
	if(s[0][0] == 'G') :
		wt = 2
	for j in s :
		if(j[0] == '1' or j[0] == '2' or j[0] == '3') :
			if(int(j) not in d ) :
				d[int(j)] = wt
			else :
				d[int(j)] += wt
ma = 0
num = 0
for j in d:
	if(d[j] > ma) :
	    ma = d[j]
	    num = j
count = 0
for j in d.values() :
    if(j == ma) :
        count += 1
if(count > 1) :
	print("No Date")
elif(num == 20 or num == 19):
	print("Date")
else :
    print("No Date")