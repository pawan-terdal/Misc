"""Crawler."""

import requests
import re
import webbrowser


urlRegex = re.compile(r'https://medium.com/[^"]+')
response = requests.get('https://medium.com/')
text = response.text
urls = urlRegex.findall(text)
length = len(urls)
i = 0
while(i < length):
    if(urls[i].find('reading_list') == -1 or urls[i].find('tagged') != -1):
        del urls[i]
        length -= 1
        i -= 1
    i += 1

newUrls = []
for url in urls:
    if(url in newUrls):
        continue
    newUrls.append(url)

print(len(newUrls))
thresholdLikes = 20
finalUrls = []
urlRegex = re.compile(r'>(\d+)</button>')
for url in newUrls:
    response = requests.get(url)
    text = response.text
    if(int(urlRegex.search(text).group(1)) > thresholdLikes):
        print(url)
        webbrowser.open(url)
        finalUrls.append(url)

print(len(finalUrls))
