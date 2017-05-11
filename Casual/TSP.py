"""Travelling Salesman Problem."""

import copy
from pprint import pprint

costTable = {}
parentTable = {}
startvertex = 1


def FillTable(vertex, mySet):
    """Fill the tables."""
    if(len(mySet) == 0):
        return
    mySSet = [str(num) for num in mySet]
    finalKey = str(vertex) + "," + "-".join(mySSet)
    if(finalKey in costTable.keys()):
        return

    for i in mySet:
        newSet = copy.deepcopy(mySet)
        newSet.remove(i)
        for j in range(nVertices):
            if j == startvertex or j in newSet:
                continue
            FillTable(j, newSet)
    costTable[finalKey] = -1
    parentTable[finalKey] = -1
    return


def Satisfy(key, subKey):
    """Satisfaction Thing."""
    for char in key:
        if(char == "," or char == '-'):
            continue
        try:
            subKey.index(char)
        except(ValueError):
            return False
    return True


def FindPath(myKeys):
    """Find the route."""
    path = []
    key = myKeys[-1]
    while len(path) != nVertices:
        shortListedKeys = [i for i in myKeys[::-1]
                           if i.startswith(str(parentTable[key]))]
        path.append(str(parentTable[key]))
        minCost = 10000000
        for connectedKey in shortListedKeys:
            if(len(key) - len(connectedKey) > 2):
                continue
            if(costTable[connectedKey] < minCost):
                minCost = costTable[connectedKey]
                nextKey = connectedKey

        key = nextKey
    path.reverse()
    path.append(str(startvertex))
    return path


matrix = []
nVertices = int(input())
for i in range(nVertices):
    myArr = [int(num) for num in input().split(' ')]
    matrix.append(myArr)


mySet = []
for num in range(nVertices):
    mySet.append(num)
mySet.remove(startvertex)

for num in mySet:
    costTable[str(num) + ","] = matrix[startvertex][num]
    parentTable[str(num) + ","] = startvertex

print(mySet)
FillTable(startvertex, mySet)
myKeys = sorted(costTable.keys(), key=len)

for key in myKeys:
    keyLength = len(key)
    minCost = 10000000
    minVertex = -1
    if(costTable[key] != -1):
        continue
    for subKey in myKeys:
        subKeyLength = len(subKey)
        if(subKeyLength == keyLength):
            break
        if(Satisfy(key[2:], subKey)):
            myCost = costTable[subKey] + matrix[int(subKey[0])][int(key[0])]
            if(myCost < minCost):
                minCost = myCost
                minVertex = int(subKey[0])
    costTable[key] = minCost
    parentTable[key] = minVertex

pprint("Cost is : " + str(costTable[myKeys[-1]]))
pprint("Path is : " + "->".join(FindPath(myKeys)))
"""
4
0 1 15 6
2 0 7 3
9 6 0 12
10 4 8 0
"""
