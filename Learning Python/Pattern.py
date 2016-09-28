def Pattern(num) :
    k = num - 1
    for i in xrange(k,-k-1,-1) :
        val = 1
        for j in xrange(-k,k+1) :
            if(abs(i) >= abs(j) and val) :
                print(str(abs(i) + 1))
                val = 0
            else :
                print(" ")
                val = 1
        print("")

Pattern(3)
