#ead input from STDIN. Print output to STDOUT
from itertools import permutations 
x = raw_input().split()
for i in list(permutations(list(sorted(x[0])),int(x[1]))) :
    print (str(i).strip(')').strip('(').split(','))
	
