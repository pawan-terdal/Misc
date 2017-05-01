"""Script to join files."""

import json

file1 = open("this.txt")
file2 = open("count.txt")

dict1 = json.loads(file1.read())
dict2 = json.loads(file2.read())
for key in dict2.keys():
    dict1.setdefault(key, 0)
    dict1[key] += dict2[key]

print(len(dict1.keys()))
file1.close()
file1 = open("this.txt", 'w')
file1.write(json.dumps(dict1))
file1.close()
file2.close()
