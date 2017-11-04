"""Scrape all the links for challenges completed."""

import re
import requests


def main():
    """Main function."""
    accounts = [["Nithin", "https://www.freecodecamp.com/rednithin"],
                ["Sharad", "https://www.freecodecamp.com/sharadbhat"],
                ["Yeetesh", "https://www.freecodecamp.com/yeetesh"],
                ["Akanksh", "https://www.freecodecamp.com/akanksh5"],
                ["Shiraz", "https://www.freecodecamp.com/mshirazab"],
                ["Sudeep", "https://www.freecodecamp.com/mungarasudeep"],
                ["Yedida", "https://www.freecodecamp.com/yrahul3910"],
                ["Krishna", "https://www.freecodecamp.com/krishnarao-C"],
                ["Ruta", "https://www.freecodecamp.com/Ruta-U"],
                ["Mohak", "https://www.freecodecamp.com/mohak666"]]

    dic = {}
    for account in accounts:
        response = requests.get(account[1])
        completed = re.compile(r">\[\s(\d+)\s\]<").search(response.text)
        dic[account[0]] = int(completed[1])

    top_to_bottom = list(reversed(sorted(dic, key=dic.__getitem__)))

    for person in top_to_bottom:
        print(person + "\t : " + str(dic[person]))


if __name__ == '__main__':
    main()
