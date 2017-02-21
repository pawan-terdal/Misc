import matplotlib.pyplot as plt
x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 1, 12]
plt.scatter(x=x, y=y)
plt.show()
print('Enter your name :')
while True:
    name      = input()
    if name:
        print('Hello ' + name)
        break
    else:
        print('Enter your name again')
