import numpy as np

def Partition(arr, start, end):
    pIndex = start
    pivot = end
    for i in range(start,end):
        if arr[i] <= arr[pivot] :
            temp = arr[pIndex]
            arr[pIndex] = arr[i]
            arr[i] = temp
            pIndex += 1

    temp = arr[pIndex]
    arr[pIndex] = arr[pivot]
    arr[pivot] = temp
    return pIndex

def QuickSort(arr, start, end):
    if start >= end :
        return
    pIndex = Partition(arr,start,end)
    QuickSort(arr,start, pIndex-1)
    QuickSort(arr,pIndex+1, end)


a = list(np.random.randint(0,100,20))
print("Unsorted List : " + str(a))
QuickSort(a,0,len(a)-1)
print("Sorted List : " + str(a))
