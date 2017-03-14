#!/usr/bin/python3

from Groove import *
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.properties import ObjectProperty
from kivy.uix.listview import ListItemButton
from kivy.uix.popup import Popup

filepath = "/"

class CustomPopup(Popup):
    def dismiss(self, path, selection):
        global filepath
        if(len(selection) != 0):
            filepath = "/" + selection[0][1:]
        super().dismiss()
        
class TrackListButton(ListItemButton):
    def __init__(self, **kwargs):
        super(TrackListButton, self).__init__(**kwargs)
        self.font_size=18
        self.height=32

class TrackDB(BoxLayout):
    search_text_input = ObjectProperty()
    track_list = ObjectProperty()
    response = []

    def search_tracks(self):
        if(self.search_text_input != ""):
            musicClient = Groove()
            self.response = musicClient.Search(self.search_text_input.text)

            self.track_list.adapter.data = []

            for item in self.response:
                self.track_list.adapter.data.extend(["{} [{}]  by {}".format(item.TrackName,item.AlbumName,';'.join(item.Artists))])
            self.track_list._trigger_reset_populate()
    
    def select_file(self):
        mypopup = CustomPopup()
        mypopup.open()

    def save_tags(self):
        global filepath
        if(self.track_list.adapter.selection and filepath != '/'):
            for item in self.response:
                if(self.track_list.adapter.selection[0].text == "{} [{}]  by {}".format(item.TrackName,item.AlbumName,';'.join(item.Artists))):
                    saveClient = SaveClient()
                    saveClient.Save(item,filepath)
                    filepath='/'
                    break

class GroovyApp(App):
    def build(self):
        return TrackDB()

dbApp = GroovyApp()
dbApp.run()