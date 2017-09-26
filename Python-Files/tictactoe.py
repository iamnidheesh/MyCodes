board={'top-L':' ','top-M':' ','top-R':' ',
       'mid-L':' ','mid-M':' ','mid-R':' ',
       'low-L':' ','low-M':' ','low-R':' '}
def printboard(board):
    print(board['top-L']+'|'+board['top-M']+'|'+board['top-R'])
    print('-+-+-')
    print(board['mid-L']+'|'+board['mid-M']+'|'+board['mid-R'])
    print('-+-+-')
    print(board['low-L']+'|'+board['low-M']+'|'+board['low-R'])
print('X TURN')
p="top-L top-M top-R mid-L mid-M mid-R low-L low-M low-R"
turn='X'
p=p.split();
pos=' '
c=0
while 1:
    if board[p[0]]==board[p[1]]==board[p[2]]!=' ' or board[p[0]]==board[p[3]]==board[p[6]]!=' ' or board[p[0]]==board[p[4]]==board[p[8]]!=' ' or board[p[1]]==board[p[4]]==board[p[7]]!=' ' or board[p[2]]==board[p[5]]==board[p[8]]!=' ' or board[p[6]]==board[p[4]]==board[p[2]]!=' ' or board[p[3]]==board[p[4]]==board[p[5]]!=' ' or board[p[6]]==board[p[7]]==board[p[8]]!=' ' :
                if turn=='X' :
                    turn='0'
                else :
                    turn ='X'
                print(turn + "won")
                break;
    elif c==9 :
        print("MATCH DRAW")
        break;
    pos=input('position')
    c=c+1
   
    if pos in p :                  
        if board[pos]!=' ' :
            print('positon occupied retry!!!')
            continue
        if turn=='X' :
            board[pos]=turn
            turn='0'
            printboard(board)
            print('0 TURN ')
         
        elif turn=='0' :
            board[pos]=turn
            turn='X'
            printboard(board)
            print('X TURN')
    else :
        print("invalid entry")
        print("try--> top-L top-M top-R mid-L mid-M mid-R low-L low-M low-R ")
       
    
    
