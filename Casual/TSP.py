"""Travelling Salesman Problem."""

import copy
from pprint import pprint

costTable = {}
parentTable = {}
startvertex = 0


def FillTable(vertex, mySet):
    """Fill the tables."""
    print(str(vertex) + "--------" + str(mySet))
    if(len(mySet) == 0):
        return
    mySSet = [str(num) for num in mySet]
    minCost = 100000
    minVertex = -1

    finalKey = str(vertex) + "," + "-".join(mySSet)
    if(finalKey in costTable.keys()):
        return

    for i in mySet:
        newSet = copy.deepcopy(mySet)
        newSet.remove(i)
        newSSet = [str(num) for num in newSet]
        for j in range(nVertices):
            if j == startvertex or j in newSet:
                continue
            myKey = str(j) + "," + "-".join(newSSet)
            FillTable(j, newSet)

            print(str(j) + "--------" + str(vertex) + "------" +
                  str(costTable[myKey]))
            input()
            myCost = costTable[myKey] + matrix[j][vertex]
            if(myCost < minCost):
                minCost = myCost
                minVertex = j
    costTable[finalKey] = minCost
    parentTable[finalKey] = minVertex
    return


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
    parentTable[str(num) + ","] = 0

FillTable(startvertex, mySet)
pprint(costTable)
pprint(parentTable)

"""
4
0 1 15 6
2 0 7 3
9 6 0 12
10 4 8 0
"""
