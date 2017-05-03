"""Scrape all the links for challenges completed."""
import re
import requests

accounts = [["Nithin", "https://www.freecodecamp.com/rednithin"],
            ["Sharad", "https://www.freecodecamp.com/sharadbhat"],
            ["Yeetesh", "https://www.freecodecamp.com/yeetesh"],
            ["Akanksh", "https://www.freecodecamp.com/akanksh5"],
            ["Shiraz", "https://www.freecodecamp.com/mshirazab"],
            ["Sudeep", "https://www.freecodecamp.com/mungarasudeep"],
            ["Yedida", "https://www.freecodecamp.com/yrahul3910"],
            ["Krishna", "https://www.freecodecamp.com/krishnarao-C"],
            ["Ruta", "https://www.freecodecamp.com/Ruta-U"]]

d = {}
for account in accounts:
    response = requests.get(account[1])
    completed = re.compile(r">\[\s(\d+)\s\]<").search(response.text)
    d[account[0]] = int(completed[1])

topToBottom = list(reversed(sorted(d, key=d.__getitem__)))

for person in topToBottom:
    print(person + "\t : " + str(d[person]))
