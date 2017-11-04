#!/usr/bin/python3
"""Script to notify results."""

import re
from tkinter import Tk
from time import sleep
import requests


def main():
    """Main function."""
    i = 1
    reg = re.compile(r"nithin")
    while True:
        url = "http://results.vtu.ac.in/cbcs_17/result_page.php?usn=1pe15is072"
        try:
            arr = reg.findall(requests.get(url).text.lower())
            print("{0}\r".format(str(i)), end="")
            if arr:
                print("Satisfied")
                for i in range(5000):
                    Tk().bell()

            sleep(300)
        except (KeyboardInterrupt, SystemExit):
            raise
        except:
            continue
        i += 1


if __name__ == '__main__':
    main()
