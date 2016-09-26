def Cyclotron(v):
    r=[ ((3.344*(10**-27)*v)/(1.603 * (10**-19) * (1.600**2)))**.5 ]
    while(r[-1] < .6):
        r.append((r[-1]**2 + 2 *(3.344*(10**-27)*v)/(1.603 * (10**-19) * (1.600**2)))**.5)
    print("Number of radii : " + str(len(r)))
    x = r[0]/2
    n = 0
    while(x < .5):
        x += ((-1)**(n+1)) * 2 * r[n]
        n += 1
    print("Number of crosses : " + str(n))
    print("Energy : " + str(v*n*10**-6))

Cyclotron(480000)
