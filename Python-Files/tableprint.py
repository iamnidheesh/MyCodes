tableData	=	[['apples', 'oranges',	'cherries', 'banana'],
			 ['Alice','Bob','Carol','David'],
		         ['dogs','cats','moose','goose']]
def printtable(tdata):
    m=[0,0,0]
    m[0]=max(len(tdata))
    for i in tdata:
        for j in i :
            print(j.ljust(m[i]),end=' ')
        print()
printtable(tableData)
