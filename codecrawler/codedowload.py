#!/usr/bin/env python
# -*- coding:utf-8 -*-
import re, os, time
from lxml import etree
from codecrawler.login import Login
from bs4 import BeautifulSoup
import threading

class CrawlCode(object):
    def __init__(self):
        self.login = Login()
        self.session = self.login.session
        self.pids = self.get_solved()

    def get_solved(self):
        url = 'http://acm.hdu.edu.cn/userstatus.php?user=%s' % self.login.username
        r = self.session.get(url)
        soup = BeautifulSoup(r.text, 'lxml')
        list = soup.find('p', align='left')
        solved = []
        for item in list.text.split(';'):
            if item:
                item = re.search(r'\d{4}', item)
                solved.append(item.group(0))
        print("solved.size : %d" % len(solved))
        return solved

    def save_code(self, pid, rid, code):
        path = '_code/hdu' + pid
        if os.path.exists(path) == False:
            os.mkdir(path);
        filename = path + '/' + rid + '.cpp'
        fd = open(filename, 'w+')
        fd.write(code)

    def get_code(self, pid, rid):
        url = 'http://acm.hdu.edu.cn/viewcode.php?rid=' + rid
        headers = {
            'Content-Type': 'text/html',
            'Host': 'acm.hdu.edu.cn',
            'Cookie':'PHPSESSID=0hdpjvo7t4t9nl9jgn5bnes3g2',
            'Referer': 'http://acm.hdu.edu.cn/status.php?first=&pid=%s&user=%s&lang=0&status=5' % (pid, self.login.username),
            'User-Agent': self.login.UA
        }
        self.session.headers.update(headers)
        r = self.session.get(url)
        soup = BeautifulSoup(r.text, 'lxml')
        code = soup.find(id='usercode').text
        self.save_code(pid, rid, code)

    def get_records(self):
        sleep_time = 0.05
        for pid in self.pids:
            print('sleep time: %.3f s' % sleep_time)
            time.sleep(sleep_time)
            url = 'http://acm.hdu.edu.cn/status.php?first=&pid=%s&user=%s&lang=0&status=5' % (pid, self.login.username)
            r = self.session.get(url)
            soup = BeautifulSoup(r.text, 'lxml')
            table = soup.find(id='fixed_table').find_all('tr', align='center')
            print('pid=%s, totals=%d' % (pid, len(table)))
            for item in table:
                rid = next(item.children).text
                print('rid=' + rid)
                self.get_code(pid, rid)


if __name__ == '__main__':
    go = CrawlCode()
    go.get_records()
