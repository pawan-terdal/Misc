#!/usr/bin/python3
"""Send a Mail."""


import os
import smtplib


def SendMail():
    """Send a mail."""
    fromAddr = 'reddy.nithinpg@gmail.com'
    toAddr = 'sharad.mbhat@gmail.com'
    message = "I am asleep. AND AUTOMATION LOL XD"
    username = "reddy.nithinpg@gmail.com"
    password = "jifdynastywar88"
    try:
        server = smtplib.SMTP('smtp.gmail.com:587')
        server.starttls()
        server.login(username, password)
        server.sendmail(fromAddr, toAddr, message)
        server.quit()
        return True
    except:
        return False


def IsNotAwake():
    """I am not awake."""
    os.chdir("/home/nithin/Desktop")
    f = open("input.txt", 'a')
    f.close()
    f = open("input.txt")
    text = f.read()
    f.close()
    open("input.txt", 'w').close()
    if(not text):
        return True
    else:
        return False


os.chdir("/home/nithin/Desktop")
f = open("output.txt", 'a')

if(IsNotAwake()):
    if(SendMail()):
        f.write("Sent Mail...\n")
    else:
        f.write("No internet...Mail sending failed...\n")
else:
    f.write("Cancelled...\n")

f.close()
