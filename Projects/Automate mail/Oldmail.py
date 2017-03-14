#!/usr/bin/python3

import signal
from tkinter import messagebox
import os

class AlarmException(Exception):
    pass

def alarmHandler(signum, frame):
    raise AlarmException

def nonBlockingRawInput(prompt='', timeout=5):
    signal.signal(signal.SIGALRM, alarmHandler)
    signal.alarm(timeout)
    try:
        text = input()
        signal.alarm(0)        
        return text
    except AlarmException:
        print(os.getcwd())
        f = open("./lol.txt",'a')
        f.write('\nPrompt timeout. Continuing...')
    signal.signal(signal.SIGALRM, signal.SIG_IGN)
    return ''

print(nonBlockingRawInput())
