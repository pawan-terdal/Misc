#!/usr/bin/python3

import requests
import urllib.parse
import copy


class Track:

    def __init__(self):
        self.TrackName   = ""
        self.Albumname   = ""
        self.ImageUrl    = ""
        self.Artists     = []
        self.Genres      = []
        self.Subgenres   = []
        self.TrackNumber = 0
        self.Year        = 0


class Groove:
    clientid     = 'rednithin'
    clientsecret = 'GitUOgchj++wiZuYx8rEuOorkB4gu5Keij5BaKyMafk='
    serviceauth  = "https://datamarket.accesscontrol.windows.net/v2/OAuth2-13"
    serviceapi   = "https://music.xboxlive.com/1/content"
    scope        = "http://music.xboxlive.com"
    grantType    = "client_credentials"

    def Search(self, key):
        requestData                  = {}
        requestData["client_id"]     = self.clientid
        requestData["client_secret"] = self.clientsecret
        requestData["scope"]         = self.scope
        requestData["grant_type"]    = self.grantType

        response        = requests.post(self.serviceauth, data=requestData)
        accessToken     = response.json()['access_token']
        myurl           = self.serviceapi + '/music/search?q=' + \
            urllib.parse.quote_plus(key) + '&maxItems=24&filters=Tracks' + \
            '&accessToken=Bearer+' + urllib.parse.quote_plus(accessToken)
        contentResponse = requests.get(myurl)

        contentJson     = contentResponse.json()

        tracks = []
        for item in contentJson['Tracks']['Items']:
            track           = Track()
            track.TrackName = item['Name']
            track.Albumname = item['Album']['Name']
            track.ImageUrl  = item['Album']['ImageUrl']
            for artist in item['Artists']:
                track.Artists.append(artist['Artist']['Name'])
            track.Genres      = copy.deepcopy(item['Genres'])
            track.Subgenres   = copy.deepcopy(item['Subgenres'])
            track.TrackNumber = int(item['TrackNumber'])
            track.Year        = int(item['ReleaseDate'][0:4])
            tracks.append(copy.deepcopy(track))
        return tracks
