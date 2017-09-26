#the Collatz sequence
def collatz(m):
    if m%2==0 :
        m=m//2
        return m
    elif m%2==1 :
        m=3*m+1
        return m
c=0
while c!=1 :
    try :
        n=int(input("Enter number :"))
        c=c+1
        while True :
            print(n)
            n=collatz(n)
            
            if n==1 :
                break

    except :
        print("please enter an integer")
