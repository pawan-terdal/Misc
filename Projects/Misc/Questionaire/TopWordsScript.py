"""Script to Get the Top Most Used Words."""

import json
import re


f = open("this.txt")
d = json.loads(f.read())
print("Number of Words Indexed : " + str(len(d)))
print("Enter sweet spot : ", end='')
sweetSpot = int(input().strip())
mostUsedWords = sorted(d, key=d.__getitem__)[-sweetSpot:]
#print(mostUsedWords)

keywords = []
f.close()
f = open("para.txt")
words = re.compile("[a-zA-Z]+").findall(f.read())
for word in words:
    if word.lower() not in mostUsedWords and word.lower() not in keywords:
        keywords.append(word.lower())

print(keywords)
