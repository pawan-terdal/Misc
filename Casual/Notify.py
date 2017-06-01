#!/usr/bin/python3
"""Script to notify results."""

import requests
import re
from tkinter import Tk
from time import sleep

i = 1
reg = re.compile(r"(all|bengaluru)")
while(True):
    url = "http://result.vtu.ac.in"
    try:
        arr = reg.findall(requests.get(url).text.lower())
        print("{0}\r".format(str(i)), end="")
        if(len(arr) != 0):
            print("Satisfied")
            for i in range(5000):
                Tk().bell()

        sleep(300)
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        continue
    i += 1
