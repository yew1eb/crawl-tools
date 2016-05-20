#!/usr/bin/env python
# -*- coding:utf-8 -*-
import re
from lxml import etree
from bs4 import BeautifulSoup
import os, sys


for i in range(1000, 6000):
    pid = str(i)
    file = 'codecrawler/_code/hdu'+pid+'/'+pid+'.cpp'
    if os.path.isfile(file):
        os.remove(file)
        print(file)