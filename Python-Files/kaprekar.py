p=int(input())
q=int(input())
flag=0
for i in range (p,q):
    i=i*i
    nl=int(len(str(i))/2)
    nr=len(str(i))-nl
    s=str(i)[0:nl-1]+' '+str(i)[nr-1:len(str(i))]
    s=s.split()
    print(s)
    if (int(s[0])+int(s[1])==i**0.5):
        flag=1
        print(i**0.5,end=' ')
if flag==0:
    print("INVALID RANGE")
                                        
    
    
