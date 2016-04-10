#!/usr/bin/env python
# -*- coding:utf-8 -*-

import urllib.request
import re
import datetime
from bs4 import BeautifulSoup
from http.server import HTTPServer, BaseHTTPRequestHandler
from apscheduler import schedulers
import redis
from crawl_jd.config import *
from crawl_jd import crawler

if __name__ == '__main__':
    crawler_jd = crawler(TITLE_INCLUDE_KEYWORD, TITLE_LIMIT_KEYWORD, JOB_SOURCES)
    crawler_jd.run()
    sched = Scheduler()
