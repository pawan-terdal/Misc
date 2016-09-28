def Pattern(num) :
    k = num - 1
    for i in xrange(k,-k,-1) :
        val = 1
        for j in xrange(-k,k) :
            if(abs(i) > abs(j)) :
                print(str(abs(i) + 1),end='\0')
                val = 0
            else :
                print(" ",end='\0')
                val = 1
        print()

Pattern(3)
