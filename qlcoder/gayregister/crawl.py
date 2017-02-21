#!/usr/bin/env python
# -*- coding:utf-8 -*-


from urllib import request, parse
import re
from lxml import etree,html

url = 'http://www.qlcoder.com/train/gayregister'

def getPage(url):
    req = request.Request(url)
    page = request.urlopen(req).read()
    page = page.decode('utf-8')
    return page

html_content = getPage(url)
selectors = etree.HTML(html_content)
imgs = selectors.xpath("//input[@type='text']")
for img in imgs:
    img.get('name')