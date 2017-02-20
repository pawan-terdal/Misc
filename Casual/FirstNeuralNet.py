theta = [-30,20,20]
def AndNeuron(x1, x2):
    z = theta[0] + theta[1]*x1 + theta[2]*x2
    y = 1/(1+2.718281**-z)
    return y


print("0 AND 0 :" + str(AndNeuron(0,0)))
print("0 AND 1 :" + str(AndNeuron(0,1)))
print("1 AND 0 :" + str(AndNeuron(1,0)))
print("1 AND 1 :" + str(AndNeuron(1,1)))