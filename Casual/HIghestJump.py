import urllib.request
from lxml import html
import re

for i in range(1,123):
    url1 = 'http://result.vtu.ac.in/cbcs_results2016.aspx?usn=1PE15IS{0:03d}&sem=2'.format(i)
    url2 = "http://result.vtu.ac.in/cbcs_resultsRV2016.aspx?usn=1PE15IS{0:03d}&sem=2".format(i)
    html1 = urllib.request.urlopen(url1).read()
    html2 = urllib.request.urlopen(url2).read()
    nameObj = re.compile(r'<span id="lblname" style="Z-INDEX: 101; POSITION: absolute; TOP: 216px; LEFT: 88px">Name</span><input name="txtName" type="text" value="(\w{,30}\s{,2}\w{,30}\s{,2}\w{,30}\s{,2})"')
    eleObj1 = re.compile(r'lblSGPA.*>(\d(\.){,1}(\d{,2}))<')
    eleObj2 = re.compile(r'lblSGPA.*>(\d(\.){,1}(\d{,2}))<')
    name = nameObj.findall(str(html1))
    l1 = eleObj1.findall(str(html1))
    l2 = eleObj2.findall(str(html2))
    if(name and l1 and l2):
        print(name[0] + " " + str(i) + "\t : " + "{0:.2f}".format(float(l2[0][0]) - float(l1[0][0])))