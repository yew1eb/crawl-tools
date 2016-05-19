#!/usr/bin/env python
# -*- coding:utf-8 -*-
import re, os

from bs4 import BeautifulSoup

from codecrawler.login import Login


class Submit(object):
    def __init__(self):
        self.login = Login()
        self.session = self.login.session
        self.pids = self.get_solved()
        self.needs = []
        pass

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

    def submit(self, pid, code, lang=0):
        """
        0 - G++, 1 - GCC, 2 - C++, 3 - C, 4 - Pascal, 5 - Java, 6 - C#
        """
        url = 'http://acm.hdu.edu.cn/submit.php?action=submit'
        code = code.encode('utf-8').decode()
        data = {
            'check': '0',
            'problemid': str(pid),
            'language': str(lang),
            'usercode': code
        }
        headers = {
            'Connect-Type': 'application/x-www-form-urlencoded'
        }
        print('submitting problem: ', pid)
        r = self.session.post(url, data=data, headers=headers)

    def get_file(self):
        root = '_code'
        dirs = os.listdir(root)
        for dir in dirs:
            pid = dir[3:]
            if pid in self.pids:
                continue
            path = root + '/' + dir
            for file in os.listdir(path):
                key = pid + ':' + path + '/' + file
                self.needs.append(key)

    def start(self):
        self.get_file()
        for item in self.needs:
            list = item.split(':')
            pid = list[0]
            fd = open(list[1],'w+')
            code = fd.readlines()
            print(code)
            break

if __name__ == '__main__':
    go = Submit()
    go.start()