
#nodes explored
#path
def check(travel):
	if(vis[travel[0]][travel[1]] == -1 and travel[0] >= 0 and travel[0] < dim[0] and travel[1] >= 0 and travel[1] < dim[1]):
		if(grid[travel[0]][travel[1]] == '-' or grid[travel[0]][travel[1]] == '.'):
			return True
		else:
			return False
	else:
		return False	
	
def dfs(s,d) :
	l = []
	l.append(s)
	vis[s[0]][s[1]] = 0
	result = -1
	count = 0
	parent = [[(-1,-1)]*dim[1] for i in range(dim[0])]
	row = [-1,0,0,1]
	col = [0,-1,1,0]
	while(len(l) != 0):
		curr = l.pop()
		count += 1
		explored.append(curr)
		if(curr[0] == d[0] and curr[1] == d[1]) :
			result = vis[curr[0]][curr[1]]
			break
		for index in range(4) :
			u,v = curr[0]+row[index] , curr[1]+col[index]

			if(check([u,v])):
				vis[u][v] = 1 + vis[curr[0]][curr[1]] 
				l.append([u,v])
				parent[u][v] = (curr[0],curr[1])
		
	return (result,count,parent)



source = list(map(int,input().split()))
destination = list(map(int,input().split()))
dim = list(map(int,input().split()))
grid = [input() for i in range(dim[0])]
#print(grid)
vis = [[-1]*dim[1] for i in range(dim[0])]
explored = []
(result,count,parent) = dfs(source,destination)
temp = destination
path = []
while(parent[temp[0]][temp[1]] != (-1,-1)) :
	path.append((temp[0],temp[1]))
	temp = parent[temp[0]][temp[1]]
path.append(source)
path.reverse()
print(count)
for i in explored :
	print(i[0],i[1])
print(result)
for i in path:
	print(i[0],i[1])
