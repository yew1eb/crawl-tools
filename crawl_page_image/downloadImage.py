# -*- coding:UTF-8 -*-
# !/usr/bin/python3

import requests
import threading
from bs4 import BeautifulSoup
import re


webUrl = 'http://docs.spring.io/spring/docs/current/spring-framework-reference/html/'

def saveImage(imgUrl, imgName="default.jpg"):
    response = requests.get(webUrl+imgUrl, stream=True)
    image = response.content
    path = "image/" + imgName
    print("保存文件: " + path + "\n")
    try:
        file = open(path, 'wb')
        file.write(image)
        file.close()
    except IOError:
        pass


def downImage(filelist):
    for file in filelist:
        arr = file.strip().split('/')
        print(arr)
        filename = arr[len(arr)-1]
        print(filename)
        saveImage(file, filename)

def getfilelist(pageUrl):
    web = requests.get(pageUrl)
    soup = BeautifulSoup(web.text, "lxml")
    filelist = []
    for photo in soup.find_all('img'):
        filelist.append(photo.get('src'))
    return filelist


def getweblist(webUrl):
    web = requests.get(webUrl)
    soup = BeautifulSoup(web.text, "lxml")
    '''
    weblist = []
    for pagelist in soup.find_all('div', {'class': 'metaRight'}):
        for link in pagelist.find_all('a'):
            weblist.append(link.get('href'))
    '''
    weblist = ['http://docs.spring.io/spring/docs/current/spring-framework-reference/html/mvc.html#mvc']
    return weblist

if __name__ == "__main__":

    list = getweblist(webUrl)
    for page in list:
        print(page)
        imagelist = getfilelist(page)
        print('imagelist.size: ', len(imagelist))
        downImage(imagelist)
