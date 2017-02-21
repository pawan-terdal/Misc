#!/usr/bin/python3
from Groovy import *
from kivy.app import App
from kivy.uix.image import AsyncImage
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.scrollview import ScrollView
import requests
from io import BytesIO
import PIL
import os

os.chdir('/home/nithin')

class myWidget(GridLayout):
    def __init__(self, album, url, **kwargs):
        super(myWidget, self).__init__(**kwargs)
        self.cols = 2
        self.height=200
        self.add_widget(Label(text=album))
        response = requests.get(url+"&w=75&h=75")
        """
        img = PIL.Image.open(BytesIO(response.content))
        img.save('lol.jpg')
        """
        self.add_widget(AsyncImage(source=url+"&w=25&h=25&ext=.png"))


class LoginScreen(GridLayout):
    def __init__(self, **kwargs):
        super(LoginScreen, self).__init__(**kwargs)
        groove = Groove()
        lols = groove.Search("Hello")
        self.rows = len(lols)
        for lol in lols:
            self.add_widget(myWidget(album=lol.Albumname,url=lol.ImageUrl))

class MyApp(App):
    def build(self):
        return LoginScreen()


if __name__ == '__main__':
    MyApp().run()
