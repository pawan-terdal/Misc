import urllib.request
from lxml import html
import re

for i in range(1,188):
    url1 = 'http://result.vtu.ac.in/cbcs_results2016.aspx?usn=1PE15IS{0:03d}&sem=2'.format(i)
    url2 = "http://result.vtu.ac.in/cbcs_resultsRV2016.aspx?usn=1PE15IS{0:03d}&sem=2".format(i)
    html1 = urllib.request.urlopen(url1).read()
    html2 = urllib.request.urlopen(url2).read()
    #nameObj = re.compile(r'name="txtName" value="(\w+)')
    eleObj1 = re.compile(r'Basic.*name="txtGardeLetter5" type="text" value="(\w).*Work')
    eleObj2 = re.compile(r'Basic.*name="txtGardeLetter5" type="text" value="(\w).*RV.*Work')
    l1 = eleObj1.findall(str(html1))
    l2 = eleObj2.findall(str(html2))
    if(l1 and l1[0] == 'F' and l2):
        print(str(i) + "\t : " + str(ord(l1[0])-ord(l2[0])))