import copy

def hash(board) :
	c = 1
	sum = 0
	for i in range(3) :
		for j in range(3):
			sum += c*c*board[i][j]
			c += 1
	return sum


def ppath(board) :
	
	print(board[0])
	print(board[1])
	print(board[2])
	print()

def swap(board,x,y,g,h) :

	temp = board[x][y]
	board[x][y] = board[g][h]
	board[g][h] = temp

def issolved(board) :
	c = 1
	for i in range(3) :
		for j in range(3) :
			if(board[i][j] == 0) :
				continue
			elif(board[i][j] == c):
					c += 1
			else :
				break
	if(c == 9) :
		return True
	else :
		return False

def puzzle(board,x,y) :
	#print("hello")
	vis[hash(board)] = 1
	if(issolved(board)) :
		newboard = copy.deepcopy(board)
		steps.append(newboard)
		return True

	invlist = []
	if(x < 2) :
		swap(board,x,y,x+1,y)
		if(hash(board) not in vis or vis[hash(board)] == 0) :
			#f = puzzle(board,x+1,y)
			invlist.append((getInvCount(board),x+1,y))
		swap(board,x,y,x+1,y)
	if(x > 0) :
		swap(board,x,y,x-1,y)
		if(hash(board) not in vis or vis[hash(board)] == 0) :
			invlist.append((getInvCount(board),x-1,y))
		swap(board,x,y,x-1,y)
	if(y < 2) :
		swap(board,x,y,x,y+1)
		if(hash(board) not in vis or vis[hash(board)] == 0) :
			invlist.append((getInvCount(board),x,y+1))
		swap(board,x,y,x,y+1)
	if(y > 0) :
		swap(board,x,y,x,y-1)
		if(hash(board) not in vis or vis[hash(board)] == 0) :
			invlist.append((getInvCount(board),x,y-1))
		swap(board,x,y,x,y-1)

	invlist = sorted(invlist ,key = lambda x : x[0])
	#print (invlist)
	for i in invlist :
		swap(board,x,y,i[1],i[2])
		flag = puzzle(board,i[1],i[2])
		swap(board,x,y,i[1],i[2])
		if(flag == True) :
			newboard = copy.deepcopy(board)
			steps.append(newboard)
			return True

	vis[hash(board)] = 0
	return False
 
def getInvCount(board) :

    inv_count = 0
    arr = []
    for i in range(3):
    	for j in range(3):
    		arr.append(board[i][j])
    for i in range(8) :
        for j in range(i+1,9) :
             if (arr[j] != 0 and arr[i] != 0 and arr[i] > arr[j]) :
                  inv_count += 1
    return inv_count

def isSolvable(board) :
	
	inv_count = getInvCount(board)
	return inv_count%2 == 0

board = [input().split() for i in range(3)]
board = [[int(board[j][i]) for i in range(3)] for j in range(3)]
vis = {}
steps = []
#print (board)
if(isSolvable(board)) :
	flag = False
	for i in range(3) :
		for j in range(3) :
			if(board[i][j] == 0) :
				flag = True
				x = i
				y = j
				break
		if(flag) :
			break
	puzzle(board,x,y)
	steps.reverse()
	for i in steps :
		ppath(i)
	print("No of steps : " , len(steps)-1)
else :
	print("Not solvable")


