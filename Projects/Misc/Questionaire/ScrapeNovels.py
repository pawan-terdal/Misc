"""Scraping Novels."""

import requests
import json
import re

urls = ["http://www.gutenberg.org/cache/epub/34611/pg34611.txt",
        "http://www.gutenberg.org/cache/epub/48452/pg48452.txt",
        "http://www.gutenberg.org/cache/epub/53621/pg53621.txt",
        "http://www.gutenberg.org/cache/epub/14625/pg14625.txt",
        "http://www.gutenberg.org/cache/epub/24069/pg24069.txt",
        "http://www.gutenberg.org/cache/epub/29588/pg29588.txt",
        "http://www.gutenberg.org/cache/epub/7542/pg7542.txt",
        "http://www.gutenberg.org/cache/epub/36136/pg36136.txt",
        "https://www.gutenberg.org/files/45268/45268-0.txt",
        "http://www.gutenberg.org/cache/epub/39075/pg39075.txt",
        "http://www.gutenberg.org/cache/epub/39898/pg39898.txt",
        "http://www.gutenberg.org/cache/epub/31387/pg31387.txt",
        "https://www.gutenberg.org/files/54629/54629-0.txt",
        "https://www.gutenberg.org/files/54624/54624-0.txt",
        "http://www.gutenberg.org/cache/epub/54619/pg54619.txt",
        "https://www.gutenberg.org/files/54628/54628-0.txt",
        "https://www.gutenberg.org/files/54632/54632-0.txt",
        "https://www.gutenberg.org/files/54636/54636-0.txt",
        "https://www.gutenberg.org/files/54635/54635-0.txt",
        "https://www.gutenberg.org/files/54631/54631-0.txt",
        "http://www.gutenberg.org/cache/epub/54627/pg54627.txt",
        "https://www.gutenberg.org/files/54617/54617-0.txt",
        "http://www.gutenberg.org/cache/epub/54621/pg54621.txt",
        "https://www.gutenberg.org/files/54620/54620-0.txt",
        "https://www.gutenberg.org/files/54638/54638-0.txt"]

novelNumber = 1
wordFrequency = {}
for url in urls:
    print("Novel Number : " + str(novelNumber))
    response = requests.get(url)
    text = response.text[2000:-2000]
    wordArray = re.compile(r'[a-zA-Z]+').findall(text)
    for word in wordArray:
        wordFrequency.setdefault(word.strip().lower(), 0)
        wordFrequency[word.strip().lower()] += 1
    novelNumber += 1

print(len(wordFrequency.keys()))
wordsJson = json.dumps(wordFrequency)

file = open('this.txt', 'w')
file.write(wordsJson)
