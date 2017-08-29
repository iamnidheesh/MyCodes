
#nodes explored
from collections import deque
def check(travel):
	#print(travel[0],travel[1],vis[travel[0]][travel[1]])
	if(vis[travel[0]][travel[1]] == -1 and travel[0] >= 0 and travel[0] < dim[0] and travel[1] >= 0 and travel[1] < dim[1]):
		#print(travel[0],travel[1])
		if(grid[travel[0]][travel[1]] == '-' or grid[travel[0]][travel[1]] == '.'):
			#print(True)
			return True
		else:
			#print(False)
			return False
	else:
		return False	
def bfs(s,d) :
	l = deque()
	l.append(s)
	vis[s[0]][s[1]] = 1
	result = [-1,-1]
	while(len(l) != 0):
		curr = l.popleft()
		print(curr)
		if(curr[0] == d[0] and curr[1] == d[1]) :
			result = vis[curr[0]][curr[1]]
			break
		if(check([curr[0]-1,curr[1]])):
			#print("1")
			vis[curr[0]-1][curr[1]] = 1 + vis[curr[0]][curr[1]] 
			l.append([curr[0]-1,curr[1]])
		if(check([curr[0],curr[1]-1])):
			#print("2")
			vis[curr[0]][curr[1]-1] = 1 + vis[curr[0]][curr[1]] 
			l.append([curr[0],curr[1]-1])
		if(check([curr[0],curr[1]+1])):
			#print("3")
			vis[curr[0]][curr[1]+1] = 1 + vis[curr[0]][curr[1]] 
			l.append([curr[0],curr[1]+1])
		if(check([curr[0]+1,curr[1]])):
			#print("4")
			vis[curr[0]+1][curr[1]] = 1 + vis[curr[0]][curr[1]] 
			l.append([curr[0]+1,curr[1]])
			
		#print(l)
		
	return result
	

source = list(map(int,input().split()))
destination = list(map(int,input().split()))
dim = list(map(int,input().split()))
grid = [input() for i in range(dim[0])]
#print(grid)
vis = [[-1]*dim[1] for i in range(dim[0])]
result = bfs(source,destination)
print("No. of steps using bfs :" ,result)
