#!/usr/bin/python3

import json
import pprint
import pyperclip
import numpy as np

j = pyperclip.paste()

class Abc(object):
    def __init__(self, j) :
        self.__dict__ = json.loads(j)

p = Abc(j)
print(str(p.streams[0]["level"]))
