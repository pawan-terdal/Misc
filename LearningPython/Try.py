def hello(num):
	try:
		return 50/num
	except:
		print("Divided by zero:")

print(hello(2))
print(hello(0))
print(hello(5))
