
def get_grade(myMark):
    temp = 0
    for i in range(11):
        if(myMark >= levels[i]):
            temp = grades[i]
        else:
            break
    return temp


myMarks = [92,74,70,74,69,72,100,99]
#[91,80,77,67,65,73,98,97]
grades = [0, 0, 0, 0, 4, 5, 6, 7, 8, 9, 10]
multiplier = [4, 4, 4, 4, 4, 4, 2, 2]
Sum = 4*10*7
mySum = 0
levels = [0, 0, 0, 0, 40, 45, 50, 60, 70, 80, 90, 100]
"""
while levels[-1] < 100:
    levels.append(levels[-1] + 60/7)
"""
# myGrades = [10,6,8,7,7,7,10,10]
myGrades = []
for i in range(8):
    myGrade = get_grade(myMarks[i])
    myGrades.append(myGrade)
    #myGrade = myGrades[i]
    mySum += myGrade * multiplier[i]
print("Grades in each : " + str(myGrades))
print("Sum : " + str(mySum))
print("Max Sum : " + str(Sum))
print("SGPA : " + str(mySum*10/Sum))
