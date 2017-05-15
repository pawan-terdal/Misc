#!/usr/bin/python3
"""Script to notify results."""

import requests
import re
from tkinter import Tk
from time import sleep

i = 1
while(True):
    print(i)
    url = "http://results.vtu.ac.in/"
    try:
        arr = re.compile(r"14-05-2017 @10:25 PM").findall(requests.get(url).text)
        print("{0}\r".format(str(i)), end="")
        if(len(arr) != 1):
            print("Satisfied")
            for i in range(5000):
                Tk().bell()

        sleep(5)
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        print("LOL")
        continue
    i += 1
