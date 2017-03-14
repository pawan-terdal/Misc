#!/usr/bin/python3

import requests
import urllib.parse
import json
import pprint
import requests
import copy
import taglib
import PIL
from io import BytesIO
import mutagen
from mutagen.mp3 import MP3
from mutagen.id3 import ID3, APIC, error


class Track:
	def __init__(self):
		self.TrackName = ""
		self.AlbumName = ""
		self.ImageUrl = ""
		self.Artists = []
		self.Genres = []
		self.Subgenres = []
		self.TrackNumber = 0
		self.Year = 0

class SaveClient:
	def Save(self, item, filepath):

		response = requests.get(item.ImageUrl)
		img = PIL.Image.open(BytesIO(response.content))
		img.save("Temp.jpg")

		audio = mutagen.File(filepath)
		try:
			audio.add_tags(ID3=ID3)
		except mutagen.id3.error:
			print("has tags")
		audio.clear()
		audio.tags.add(APIC(3, 'image/jpeg', 3, u'Front Cover', open('Temp.jpg', 'rb').read()))
		audio.save()
		
		
		song = taglib.File(filepath)
		pprint.pprint(song.tags)

		song.tags['ALBUM'] = [item.AlbumName]
		song.tags['ALBUMARTIST'] = [item.Artists[0]]
		song.tags['ARTIST'] = item.Artists
		song.tags['DATE'] = [str(item.Year)]
		song.tags['GENRE'] = item.Genres
		song.tags['TITLE'] = [item.TrackName]
		song.tags['TRACKNUMBER'] = [str(item.TrackNumber)]

		song.save()
		song.close()
		
		f = open(filepath,'rb')
		f.flush()
		f.close()

		print("Done.")

class Groove:
	clientid = 'rednithin'
	clientsecret = 'GitUOgchj++wiZuYx8rEuOorkB4gu5Keij5BaKyMafk='
	serviceauth = "https://datamarket.accesscontrol.windows.net/v2/OAuth2-13"
	serviceapi = "https://music.xboxlive.com/1/content"
	scope = "http://music.xboxlive.com"
	grantType = "client_credentials"
	
	def Search(self, key):
		requestData = {}
		requestData["client_id"] = self.clientid
		requestData["client_secret"] = self.clientsecret
		requestData["scope"] = self.scope
		requestData["grant_type"] = self.grantType

		response = requests.post(self.serviceauth, data=requestData)
		accessToken = response.json()['access_token']
		myurl = self.serviceapi + '/music/search?q=' + urllib.parse.quote_plus(key) + '&maxItems=24&filters=Tracks' +'&accessToken=Bearer+' + urllib.parse.quote_plus(accessToken)
		contentResponse = requests.get(myurl)

		contentJson = contentResponse.json()

		tracks = []
		for item in contentJson['Tracks']['Items']:
			track = Track()
			track.TrackName = item['Name']
			track.AlbumName = item['Album']['Name']
			track.ImageUrl = item['Album']['ImageUrl']
			for artist in item['Artists']:
				track.Artists.append(artist['Artist']['Name'])
			track.Genres = copy.deepcopy(item['Genres'])
			track.Subgenres = copy.deepcopy(item['Subgenres'])
			track.TrackNumber = int(item['TrackNumber'])
			track.Year = int(item['ReleaseDate'][0:4])
			tracks.append(copy.deepcopy(track))
		return tracks
