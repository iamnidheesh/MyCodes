

l = []
n = int(input())
for i in range(0,n) :

    choice = input()
    if choice == 'append' :
        l.append(int(input()))
    if choice == 'insert' :
        l.insert(int(input()),int(input()))

    if choice == 'remove' :
        l.remove(int(input()))
    if choice == 'pop' :
        l.pop()
    if choice == 'index':
        print(l.index(int(input())))
    if choice == 'count' :
        print(l.count(int(input())))
    if choice == 'sort' :
        l.sort()
    if choice == 'reverse' :
        l.reverse()
    if choice == 'print' :
        print(l)


