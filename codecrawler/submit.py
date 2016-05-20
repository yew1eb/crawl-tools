#!/usr/bin/env python
# -*- coding:utf-8 -*-
import re, os, time

from bs4 import BeautifulSoup

from codecrawler.login import Login


class Submit(object):
    def __init__(self):
        self.login = Login()
        self.session = self.login.session
        self.pids = self.get_solved()
        print("solved : ", len(self.pids))
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
            'Connect-Type': 'application/x-www-form-urlencoded',
            'Cookie': 'PHPSESSID=0hdpjvo7t4t9nl9jgn5bnes3g2'
        }
        r = self.session.post(url, data=data, headers=headers)
        print('submitting problem: ', pid, 'Status Code: ', r.status_code)

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
        print("need total: ", len(self.needs))

    def start(self):
        self.get_file()
        count = 0
        last_pid = 0
        for item in self.needs:
            list = item.split(':')
            pid = list[0]
            fd = open(list[1], 'r')
            code = fd.read()
            if len(code) == 0:
                continue
            lang = 0
            if code.find('import') >= 0:
                lang = 5
            self.submit(pid, code, lang)
            time.sleep(0.2)
            count = count + 1
            if count % 10 == 0:
                print("sleep 2 s")
                time.sleep(10)


if __name__ == '__main__':
    go = Submit()

    go.start()
