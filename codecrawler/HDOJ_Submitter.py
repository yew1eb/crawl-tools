# HDOJ_SUbmitter.py
import re
from urllib import request

from bs4 import BeautifulSoup


def print_list(list):
    for item in list:
        print(item)

def getTextFromSoup(htmlsoup):
    #print(htmlsoup)
    text = str(htmlsoup)
    imgurls = []
    imgs = htmlsoup.find_all('img')
    #print_list(imgs)
    for img in imgs:
        imgurls.append('http://acm.hdu.edu.cn%s' % img['src'])
    #print(htmlsoup)
    if len(imgurls) != 0:
        for url in imgurls:
            text, number = re.subn(r'<img.+?>', r'![image](%s)' % url, text)
    #print(text)
    text, number = re.subn(r'<br>', '\n', text)
    text, number = re.subn(r'<.+?>', '', text)
    return text
    #print(text)
    #print(seh.group())
    #print_list(imgurls)
    # res = htmlsoup.replace('<br/>', '\r\n')
    # result, number = re.subn('<.+?>', '', res)
    # print(result)
    # print(number)

class problem(object):
    def __init__(self, ID, Title, Descripition='', Input='', Output='', Samplein='', Sampleout=''):
        self.ID = ID
        self.Title = Title
        self.Description = Descripition
        self.Input = Input
        self.Output = Output
        self.Samplein = Samplein
        self.Sampleout = Sampleout

    def __init__(self, ID, Title, problemItems):
        self.ID = ID
        self.Title = Title
        self.Description = problemItems[0].encode('utf-8')
        self.Input = problemItems[1].encode('utf-8')
        self.Output = problemItems[2].encode('utf-8')
        self.Samplein = problemItems[3].encode('utf-8')
        self.Sampleout = problemItems[4].encode('utf-8')

    def OutputMD(self, pos=''):
        """
        Output this to a markdown file
        """
        if not pos:
            f = open('draft_%d.md' % self.ID, 'wb')
        else:
            f = open(pos, 'wb')
        f.write(('HDU ACM %d %s' % (self.ID, self.Title)).encode('utf-8'))
        f.write(b'\n')
        f.write('##原题描述'.encode('utf-8'))
        f.write(b'\n')
        f.write(b'###Problem Description')
        f.write(b'\n')
        f.write(self.Description)
        f.write(b'\n')
        f.write(b'###Input')
        f.write(b'\n')
        f.write(self.Input)
        f.write(b'\n')
        f.write(b'###Output')
        f.write(b'\n')
        f.write(self.Output)
        f.write(b'\n')
        f.write(b'###Sample Input')
        f.write(b'\n')
        f.write(self.Samplein)
        f.write(b'\n')
        f.write(b'###Sample Output')
        f.write(b'\n')
        f.write(self.Sampleout)
        f.write(b'\n')

        f.write(b'\n')
        f.write('##解题思路'.encode('utf-8'))
        f.write(b'\n')


        f.write(b'\n')
        f.write('##参考代码'.encode('utf-8'))
        f.write(b'\n')
        f.write(b'```C++')
        f.write(b'\n')
        f.write(b'```')
        f.close()

def crawl(problemID):
    url = 'http://acm.hdu.edu.cn/showproblem.php?pid=' + str(problemID)
    text = request.urlopen(url).read().decode('latin-1')
    #text = request.urlopen(url).read().decode('latin-1')
    soup = BeautifulSoup(text, 'html.parser')
    res = soup.find_all('div', class_='panel_content')
    #print_list(res)
    title = soup.find('h1').text
    problemItems = []
    for item in res:
        problemItems.append(getTextFromSoup(item))
    prb = problem(problemID, title, problemItems)
    for i in range(0, 5):
        print(problemItems[i])
    filePosition = r'C:\WorkSpace\Blog\draft\draft_%d.md' % problemID
    prb.OutputMD(filePosition)

def submit():
    pass

if __name__ == '__main__':
    crawl(1222)