n,m = map(int,raw_input().split())
a = [(raw_input()) for i in range(n)]
b = [(raw_input()) for i in range(m)]
for i in range(0,m) :
    flag = 0
    for j in range(0,n):
        if a[j] == b[i] :
		print j+1,
            	flag = 1
  
    if(not flag):
	print -1
    else:
	print	

