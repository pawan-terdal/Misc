"""Script to scrape marks."""

import re
import requests


def download():
    """Download Marks."""
    dic = {}

    # Information Science.
    url = r"http://result.vtu.ac.in/cbcs_results2017.aspx?usn=1PE15IS{0:03d}&sem=3"
    for i in range(1, 135):
        text = requests.get(url.format(i)).text
        reg1 = re.compile("<input name=\"txtName\" type=\"text\" value=\"([^\"]*)\"")
        reg2 = re.compile("LEFT: 112px\">(.*)</span><span id=\"lblHeading\"")
        name = reg1.findall(text)
        sgpa = reg2.findall(text)
        if name:
            dic.setdefault("1PE15IS{0:03d} >>".format(i) + name[0], float(sgpa[0][3:-4]))

    # Computer Science
    url = r"http://result.vtu.ac.in/cbcs_results2017.aspx?usn=1PE15CS{0:03d}&sem=3"
    for i in range(1, 195):
        text = requests.get(url.format(i)).text
        reg1 = re.compile("<input name=\"txtName\" type=\"text\" value=\"([^\"]*)\"")
        reg2 = re.compile("LEFT: 112px\">(.*)</span><span id=\"lblHeading\"")
        name = reg1.findall(text)
        sgpa = reg2.findall(text)
        if name:
            dic.setdefault("1PE15CS{0:03d} >>".format(i) + name[0], float(sgpa[0][3:-4]))

    # Electrical Engineering
    url = r"http://result.vtu.ac.in/cbcs_results2017.aspx?usn=1PE15EC{0:03d}&sem=3"
    for i in range(1, 195):
        text = requests.get(url.format(i)).text
        reg1 = re.compile("<input name=\"txtName\" type=\"text\" value=\"([^\"]*)\"")
        reg2 = re.compile("LEFT: 112px\">(.*)</span><span id=\"lblHeading\"")
        name = reg1.findall(text)
        sgpa = reg2.findall(text)
        if name:
            dic.setdefault("1PE15EC{0:03d} >>".format(i) + name[0], float(sgpa[0][3:-4]))

    # Mechanical
    url = r"http://result.vtu.ac.in/cbcs_results2017.aspx?usn=1PE15ME{0:03d}&sem=3"
    for i in range(1, 195):
        text = requests.get(url.format(i)).text
        reg1 = re.compile("<input name=\"txtName\" type=\"text\" value=\"([^\"]*)\"")
        reg2 = re.compile("LEFT: 112px\">(.*)</span><span id=\"lblHeading\"")
        name = reg1.findall(text)
        sgpa = reg2.findall(text)
        if name:
            dic.setdefault("1PE15ME{0:03d} >>".format(i) + name[0], float(sgpa[0][3:-4]))

    count = 1
    for key in sorted(dic, key=dic.__getitem__)[::-1]:
        print(str(count) + "))" + key + ">>>" + str(dic[key]))
        count += 1


def main():
    """The main function."""
    download()


if __name__ == '__main__':
    main()
