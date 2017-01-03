#!/usr/bin/python3

import requests
import urllib.parse
import json
import pprint

import requests
clientid = 'rednithin'
clientsecret = 'GitUOgchj++wiZuYx8rEuOorkB4gu5Keij5BaKyMafk='
serviceauth = "https://datamarket.accesscontrol.windows.net/v2/OAuth2-13"
serviceapi = "https://music.xboxlive.com/1/content"
scope = "http://music.xboxlive.com"
grantType = "client_credentials"


print('Enter a music term : ', end='')
inp = input()

requestData = {}
requestData["client_id"] = clientid
requestData["client_secret"] = clientsecret
requestData["scope"] = scope
requestData["grant_type"] = grantType


t = requests.post(serviceauth, data=requestData)
accessToken = t.json()['access_token']
myurl = serviceapi + '/music/search?q=' + urllib.parse.quote_plus(inp) + '&accessToken=Bearer+' + urllib.parse.quote_plus(accessToken)
x = requests.get(myurl)

d = x.json()

pprint.pprint(d['Tracks']['Items'][0]['Name'])

for track in d['Tracks']['Items']:
	print(track['Artists'][0]['Artist']['ImageUrl'])
