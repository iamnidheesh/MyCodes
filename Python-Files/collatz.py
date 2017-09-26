#the Collatz sequence
def collatz(m):
    if m%2==0 :
        m=m//2
        return m
    elif m%2==1 :
        m=3*m+1
        return m
n=int(input("Enter number :"))
while True :
    print(n)
    n=collatz(n)
    
    if n==1 :
        break
