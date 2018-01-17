a,b,c = map(int,input().split())
from decimal import *
getcontext().prec = 1000
s = str(Decimal(a)/Decimal(b))
if(len(s) > 1000) :
	s = s[:len(s)-1]
else :
	s += '0'
index = 0
for i in s :
	if(i == '.') :
		break
	index += 1
c = str(c)
ans = 0
flag = False
l = len(s)
for i in range(index+1,l):
	ans += 1
	if(s[i] == c):
		flag = True
		break
if(flag) :
	print(ans)
else :
	print(-1)