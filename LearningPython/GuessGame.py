import random

print('Name :')
name = input()
print('Hi ' + name + ', I am thinking of a number between 1 and 20.')
randNumber = random.randint(1,20)

for i in range(5):
	print('Take a guess.')
	number = int(input())
	if(number > randNumber):
		print('Too high.')
	elif(number < randNumber):
		print('Too low.')
	else:
		break

if number == randNumber:
	print("That's Correct. You have guessed it in " + str(i+1) + " guesses.")
else:
	print("The Number is :" + str(randNumber))
