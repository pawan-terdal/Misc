"""Script to scrape content off of Hugo's Website."""

import re
import requests
import os
import sys


def PdfDownloader(url):
    """Download a PDF from the URL."""
    fileName = url.split('/')[-1]
    if fileName in os.listdir(os.getcwd()):
        return
    response = requests.get(url, stream=True)
    print("Downloading " + fileName)
    try:
        with open(fileName, 'wb') as file:
            i = 1
            for chunk in response.iter_content(chunk_size=1):
                print("\rDownloaded " + str(i) + " bytes", end='')
                sys.stdout.flush()
                file.write(chunk)
                i += 1
        print("\nDOWNLOAD COMPLETE\n")
    except KeyboardInterrupt:
        print("\rDOWNLOAD INTERRUPTED")
        os.remove(fileName)
        exit(1)


# Get HTML from site
url = "http://info.usherbrooke.ca/hlarochelle/neural_networks/content.html"
response = requests.get(url)

# Get all the links
links = re.compile(r'href="(\S+)"').findall(response.text)
# Get all pdf links from site
newLinks = []
for link in links:
    if link[-3:] == 'pdf' and link[:4] == "http" and 'usherbrooke' in link:
        newLinks.append(link)
if "pdf" not in os.listdir(os.getcwd()):
    os.mkdir("pdf")
os.chdir("./pdf")

for link in newLinks:
    PdfDownloader(link)
