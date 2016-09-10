number = 42 # Global variable

def func():
	number = 50 #Local variable
	print(number)
def change():
	global number
	number = 100

print(number)
func()
print(number)
change()
print(number)
