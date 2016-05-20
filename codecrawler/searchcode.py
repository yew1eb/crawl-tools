# ACM_Module.py
import re
import requests
import time
from bs4 import BeautifulSoup
import configparser


def print_list(list):  # 用于测试，将list中的数据分行打印
    for item in list:
        print(item)


class ACM_Module(object):
    def __init__(self):
        cf = configparser.ConfigParser()
        cf.read('config.ini')
        self.username = cf.get('user', 'username')
        self.password = cf.get('user', 'password')

        self.session = requests.Session()  # 类的session
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36'
        }
        self.session.headers.update(headers)  # 加上浏览器模拟头
        self.pids = self.get_solved()
        print("solved : ", len(self.pids))

    def login(self):

        url = 'http://acm.hdu.edu.cn/userloginex.php?action=login'

        data = {
            'username': self.username,
            'userpass': self.password,
            'login': 'Sign In',
        }
        headers = {
            'host': 'acm.hdu.edu.cn',
            'origin': 'http://acm.hdu.edu.cn',
            'referer': 'http://acm.hdu.edu.cn/'
        }
        r = self.session.post(url, data=data, headers=headers)

    def submit(self, pid, code, lang=0):
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
            'Cookie': 'PHPSESSID=rsidhr6cepo5n5c5v3q3ncdh36'
        }
        r = self.session.post(url, data=data, headers=headers)
        print('submitting problem: ', pid, 'Status Code: ', r.status_code)

    def get_solved(self):
        url = 'http://acm.hdu.edu.cn/userstatus.php?user=%s' % self.username
        r = self.session.get(url)
        soup = BeautifulSoup(r.text, 'lxml')
        #lists = soup.find_all('p', align='left')
        lists = soup.find('p', align='left')
        solved = []
        for list in lists:
            for item in list.text.split(';'):
                if item:
                    item = re.search(r'\d{4}', item)
                    solved.append(item.group(0))
        self.pids = solved
        return solved

    def hdu_discuss(self, pid):
        url = 'http://acm.hdu.edu.cn/discuss/problem/list.php?pid=%s' % pid
        solutions = []
        solutionurls = []
        r = self.session.get(url)
        soup = BeautifulSoup(r.text, 'html.parser')
        res = []
        res = soup.find_all('a', href=re.compile(
            '\./post/reply\.php\?postid=\d+&messageid=1&deep=0'))  # 用正则表达式根据url的规律解析答案discuss页的url
        # 对于每一个找到的url，拼接成完整的url
        for item in res:
            item = item['href']
            item = item[1:]  # 将点截掉
            solutionurls.append('http://acm.hdu.edu.cn/discuss/problem%s' % item)  # 拼接url

        for url in solutionurls:
            r = self.session.get(url)  # get每个完整的url
            soup = BeautifulSoup(r.text, 'html.parser')
            disshow = soup.find('pre', id='disshow').text  # 找到代码所在的tag，获取text

            diss = re.search(re.compile(r'#include.+', re.S), disshow)  # re.S 开启多行模式匹配###中间可能有空格什么的
            if diss:
                solutions.append(diss.group())  # 将代码存到要返回的list中
        return solutions

    def search_csdn(self, pid):
        url = 'https://www.baidu.com/s?ie=UTF-8&wd=hdu' + str(pid) + '%20site%3Ablog.csdn.net%20'

        baidusession = requests.Session()
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36'}
        baidusession.headers.update(headers)
        r = baidusession.get(url)
        soup = BeautifulSoup(r.text, 'lxml')
        items = soup.find_all('a', class_='c-showurl')
        solutionurls = []
        for item in items:
            solutionurls.append(item['href'])
        solutions = []
        for url in solutionurls:
            r = baidusession.get(url)
            soup = BeautifulSoup(r.text, 'lxml')
            title = soup.find('span', class_='link_title')
            print(title)
            if title:
                title = title.string
                if title.find(str(pid)) < 0:
                    continue
            else:
                continue
            code = soup.find('pre', class_='cpp')
            if code:
                #print(code.text)
                solutions.append(str(code.text))
        return solutions

    def search_cnblog(self,pid):
        url = 'https://www.baidu.com/s?ie=UTF-8&wd=hdu' + str(pid) + '%20site%3Acnblogs.com%20'

        baidusession = requests.Session()
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36'}
        baidusession.headers.update(headers)
        r = baidusession.get(url)
        soup = BeautifulSoup(r.text, 'lxml')
        items = soup.find_all('a', class_='c-showurl')
        solutionurls = []
        for item in items:
            solutionurls.append(item['href'])
        solutions = []
        for url in solutionurls:
            r = baidusession.get(url)
            soup = BeautifulSoup(r.text, 'lxml')
            title = soup.find(id='cb_post_title_url')
            if title:
                title = title.string
                if title.find(str(pid)) < 0:
                    continue
            else:
                continue
            code = soup.find('div', class_='cnblog_code')
            if code:
                print(code.text)
                solutions.append(str(code.text))
        return solutions

    def autorun(self, start=1000, end=5408):
        for pid in range(end,start,-1):
            if str(pid)  in self.pids:
                continue
            answers = self.search_csdn(pid) + self.hdu_discuss(pid) + self.search_cnblog(pid)
            print(pid, 'solutions finded: ', len(answers))
            for answer in answers:
                if str(pid) in self.get_solved():
                    break
                lang = 0
                if str(answer).find('import') >= 0 and str(answer).find('java') >= 0:
                    lang = 5
                self.submit(pid, answer, lang)
                time.sleep(2)

            print('sleep 2 s')
            time.sleep(0.5)

if __name__ == '__main__':
    c = ACM_Module()
    c.search_cnblog(5213)
    #c.login()
    #c.autorun()
