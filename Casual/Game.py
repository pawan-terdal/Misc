"""Hacker Rank."""

t = int(input().strip())
for a in range(t):
    n = int(input().strip())
    array = list(map(int, input().strip().split(' ')))
    array.append(1)
    array.append(1)
    array.append(1)
    # print(array)
    length = len(array) - 2
    count = 0
    czeros = 0
    i = 0
    while i < length:
        if(array[i] == 1 and array[i + 1] == 1):
            if(czeros - 2 >= 0):
                count += czeros - 2
            czeros = 0
            i += 1
        else:
            if(array[i] == 0):
                # print(i)
                czeros += 1
                if(array[i + 2] == 0):
                    count += 1
                    i += 1
        i += 1
    if(count % 2 == 1):
        print("Alice")
    else:
        print("Bob")
