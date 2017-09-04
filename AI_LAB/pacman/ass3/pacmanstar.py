
#nodes explored
#path
from queue import heappush,heappop
def check(travel):
	if(vis[travel[0]][travel[1]] == -1 and travel[0] >= 0 and travel[0] < dim[0] and travel[1] >= 0 and travel[1] < dim[1]):
		if(grid[travel[0]][travel[1]] == '-' or grid[travel[0]][travel[1]] == '.'):
			return True
		else:
			return False
	else:
		return False	
def mandis(point) :
	return abs(point[0] - destination[0]) + abs(point[1] - destination[1])

def astar(s,d) :
	l = []
	heappush(l,(mandis(s),s))
	vis[s[0]][s[1]] = 0
	result = -1
	count = 0
	parent = [[(-1,-1)]*dim[1] for i in range(dim[0])]
	row = [-1,0,0,1]
	col = [0,-1,1,0]
	while(len(l) != 0):
		curr = heappop(l)[1]
		if(curr[0] == d[0] and curr[1] == d[1]) :
			result = vis[curr[0]][curr[1]]
			break
		for index in range(4) :
			u,v = curr[0]+row[index] , curr[1]+col[index]

			if(check([u,v])):
				vis[u][v] = 1 + vis[curr[0]][curr[1]] 
				heappush(l,(vis[u][v] + mandis([u,v]),[u,v]))
				parent[u][v] = (curr[0],curr[1])
		
	return (result,parent)



source = list(map(int,input().split()))
destination = list(map(int,input().split()))
dim = list(map(int,input().split()))
grid = [input() for i in range(dim[0])]
vis = [[-1]*dim[1] for i in range(dim[0])]
(result,parent) = astar(source,destination)
temp = destination
path = []
while(parent[temp[0]][temp[1]] != (-1,-1)) :
	path.append((temp[0],temp[1]))
	temp = parent[temp[0]][temp[1]]
path.append(source)
path.reverse()
print(result)
for i in path:
	print(i[0],i[1])
