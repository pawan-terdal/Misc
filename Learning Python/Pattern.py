#!/usr/bin/python3

def Pattern(num) :
    k = num - 1
    for i in range(k,-k-1,-1) :
        val = 1
        for j in range(-k,k+1) :
            if(abs(i) >= abs(j) and val) :
                print(str(abs(i) + 1), end="")
                val = 0
            else :
                print(" ", end="")
                val = 1
        print("")

print("Enter num : ", end="")
num = int(input())
Pattern(num)