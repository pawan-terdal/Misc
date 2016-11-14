import sys
import copy
import random
import pprint

class Subject:
    """This is Subject Class"""
    name = ""
    rating = 0.0

def getprobabilty(arr):
    """Gets the proabilty of each occuring."""
    lol = []
    lol.append(arr[0])
    for i in range(1, len(arr)):
        lol.append(lol[i-1] + arr[i])
    for i in range(len(lol)):
        lol[i] *= 100/lol[-1]
    return lol


def printsubjects(subjects, classes=4, days=10):
    """Prints the Subjects"""
    freq = []
    for i in subjects:
        freq.append(0)
    mtable = []
    while True:
        freq.clear()
        for i in subjects:
            freq.append(0)
        mtable.clear()
        dtable = []
        prevrand = 0
        reset = []
        inc = []
        for i in subjects:
            reset.append(15 * i.rating * i.rating)
            inc.append(20)
        for i in range(days):
            if i == days // 2:
                classes += 1
            dtable.clear()
            arr = list(reset)
            for j in range(classes):
                plist = getprobabilty(arr)
                rand = random.uniform(0, 100)
                while abs(rand - prevrand) < 10:
                    rand = random.uniform(5, 100)
                prevrand = rand
                index = len(plist) - 1
                while rand < plist[index] and index >= 0:
                    index -= 1
                index += 1
                freq[index] += 1
                dtable.append(subjects[index].name)
                for k in range(len(arr)):
                    if k != index:
                        arr[k] += inc[k]
                    else:
                        arr[k] = reset[k]
            mtable.append(list(dtable))
        isproper = True
        classes -= 1
        for i in range(len(freq) - 1):
            if freq[i] >= freq[i+1]:
                isproper = False
                break

        if isproper:
            break
    start = 11
    for i in mtable:
        print(str(start) + " :::: ", end='')
        print(i)
        start = (start)%30 + 1
    print("\n")
    print(freq)

def main():
    """This is the main function."""
    subjects = []
    print("Enter Number of Subjects : ")
    num = int(input())
    print("Enter subject name followed by rating : ")
    for i in range(num):
        print("Subject {}".format(i+1))
        sub = Subject()
        sub.name = input()
        sub.rating = float(input())
        subjects.append(sub)
    subjects.sort(key=lambda x: x.rating, reverse=False)
    print("Enter number of classes per day : ")
    classes = int(input())
    print("Enter number of days : ")
    days = int(input())
    printsubjects(subjects, classes=classes, days=days)


if __name__ == '__main__':
    sys.exit(int(main() or 0))
