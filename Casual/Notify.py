#!/usr/bin/python3
"""Script to notify results."""

import requests
import re
from tkinter import Tk
from time import sleep

i = 1
reg = re.compile(r"15-05-2017 @11:15 PM")
while(True):
    url = "http://results.vtu.ac.in/results/result.php"
    try:
        arr = reg.findall(requests.get(url).text)
        print("{0}\r".format(str(i)), end="")
        if(len(arr) != 1):
            print("Satisfied")
            for i in range(5000):
                Tk().bell()

        sleep(300)
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        continue
    i += 1
