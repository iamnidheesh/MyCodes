def addtodic(invent,add):
    for i in add:
        if i in invent.keys() :
            invent[i]=invent[i]+1
        else :
            invent.setdefault(i,0)
            invent[i]=invent[i]+1
inv	=	{'gold	coin':	42,	'rope':	1}
dragonLoot	=	['gold	coin',	'dagger',	'gold	coin',	'gold	coin',	'ruby']
addtodic(inv,dragonLoot)
import pprint
pprint.pprint(inv)
