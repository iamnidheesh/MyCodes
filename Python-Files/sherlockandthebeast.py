import sys


t = int(input().strip())
for i in range(t):
    n = int(input().strip())
    if n%3==0:
        print (int(('5')*n))
    elif (n%8==3 or n%8==5 or n%8==0) :
        if n%8==3:
            print (int(str(3*(int(n/8)+1)*'5')+str(5*int(n/8)*'3')))
        if n%8==5:
            print (int(str(3*int(n/8)*'5')+str(5*int(n/8+1)*'3')))
        if n%8==0:
            print (int(str(3*int(n/8)*'5')+str(5*int(n/8)*'3')))
    elif n%5==0:
        print(int(('3')*n))
    else:
        print(-1)
    
            
