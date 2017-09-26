table=[["!","-","-","-"],["-","-","-","-"],["-","-","-","-"],["-","-","-","*"]]
def printboard(board):
    for j in range(0,4):
        for i in range(0,4):
            print(board[i][j],end='   ')
        print()
printboard(table)
print("you  postion is 0,0")
print("cpu  postion is 3,3")
u=[0,0]
c=[2,2]
import random
while(1):
    table[u[0]][u[1]]="-"
    u[0]=int(input("your new row (+-1)"))
    u[1]=int(input("you new coulmn (+-1)"))
    if((u[0]and u[1])>=0 and (u[0]and u[1])<=3) :
        table[u[0]][u[1]]="!"
    else :
        print("invalid entry retry")
        continue
    if(u==c):
        print("player wins")
        break
    print("now CPU's turn")
    table[c[0]][c[1]]="-"
    c[0]=random.randint(0,3)
    c[1]=random.randint(0,3)
    table[c[0]][c[1]]="*"
    printboard(table)
    if(u==c):
        print("c p u wins")
        break
    
	

