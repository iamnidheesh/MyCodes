def comma(b) :
    for i in b :
        if i==b[len(b)-1] :
            print("and " +i)
        else :
            print(i,end=', ')
a=input()
a=a.split()
comma(a)
