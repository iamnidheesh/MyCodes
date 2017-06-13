x=input("string1 and string2 -->")
x=x.split()
j=''
c=0
y=''
for i in x[0]:
    if i in x[1] and x[1].index(i)>x[0].index(j):
        c=c+1
        y=y+i
    else :
        y=y+'-'
if c==len(x[1]) :
    print(y)
else :
    print("not a hidden substring")
    
    
    
