# ACM_Module.py
import re
import requests
import time
from bs4 import BeautifulSoup

def print_list(list):   # 用于测试，将list中的数据分行打印
    for item in list:
        print(item)

class ACM_Module(object):
    def __init__(self):
        object.__init__(self)
        self.session = requests.Session()       # 类的session
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36'
        }
        self.session.headers.update(headers)    # 加上浏览器模拟头

    def login(self, username, password):
        """
        用用户名和密码登陆HDOJ
        :param username: 用户名
        :param password: 密码
        """
        url = 'http://acm.hdu.edu.cn/userloginex.php?action=login'

        data = {
            'username': username,
            'userpass': password,
            'login': 'Sign In',
        }
        headers = {
            'host': 'acm.hdu.edu.cn',
            'origin': 'http://acm.hdu.edu.cn',
            'referer': 'http://acm.hdu.edu.cn/'
        }
        r = self.session.post(url, data=data, headers=headers)

    def submit(self, problemID, code, language=0):
        """
        提交
        :param problemID: 题号
        :param language: 提交语言
        0 - G++
        1 - GCC
        2 - C++
        3 - C
        4 - Pascal
        5 - Java
        6 - C#
        :param code: 需要提交的代码
        """
        url = 'http://acm.hdu.edu.cn/submit.php?action=submit'
        code = code.encode('utf-8').decode()
        data = {
            'check': '0',
            'problemid': str(problemID),
            'language': str(language),
            'usercode': code
        }
        headers = {
            'Connect-Type': 'application/x-www-form-urlencoded'
        }
        se = self.session
        print('submitting problem: ', problemID)
        r = self.session.post(url, data=data, headers=headers)

    def getsolved(self, username):
        """
        获得一个用户已经解决的问题的所有题号
        :return: 返回一个含有解决问题题号的list
        :param username: 用户id
        """
        url = 'http://acm.hdu.edu.cn/userstatus.php?user=%s' % username
        solved = []
        r = self.session.get(url)
        # 解析出含有所有已完成题目号的字符串solvedstr
        soup = BeautifulSoup(r.text, 'html.parser')
        result = soup.find('p', align='left')
        solvedstr = result.text.split(';')
        # 从solvedstr中解析出一个list，含有所有完成题目号码
        for item in solvedstr:
            if item:
                item = re.search(r'\d{4}', item)    # 匹配4个数字
                solved.append(item.group(0))
        return solved

    def getstatus(self, username):
        class Status(object):
            def __init__(self, list):
                self.sub_time = list[1]
                self.status = list[2]
                self.proID = list[3]
                self.time = list[4]
                self.memory = list[5]
                self.len = list[6]
                self.lan = list[7]
            def print(self):
                print('sub_time: ',self. sub_time)
                print('status: ', self.status)
                print('proID: ', self.proID)
                print('time: ', self.time)
                print('memory: ', self.memory)
                print('len: ', self.len)
                print('lan: ', self. lan)
            def print_status(self):
                print('status: ', self.status)

        url = 'http://acm.hdu.edu.cn/status.php?user=%s' % username
        status = {}
        r = self.session.get(url)

        soup = BeautifulSoup(r.text, 'html5lib')
        soup = soup.find('table', attrs={'width': '100%', 'border': '0', 'align': 'center', 'cellspacing': '2'})
        soup = soup.find('tbody')
        soup = soup.find('tr', align='center')
        soup = soup.find_all('td')
        txtlist = []
        for item in soup:
            txtlist.append(item.text)
        s = Status(txtlist)
        return s

    def getdiscuss(self, problemID):
        """
        获取discuss中的题解
        :param problemID: 题目编号
        :return: 返回一个list，包含了discuss中的解析出来的所有题解
        """
        url = 'http://acm.hdu.edu.cn/discuss/problem/list.php?problemid=%s' % problemID
        solutions = []
        solutionurls = []

        soup = BeautifulSoup(r.text, 'html.parser')
        res = []
        res = soup.find_all('a', href=re.compile('\./post/reply\.php\?postid=\d+&messageid=1&deep=0'))  # 用正则表达式根据url的规律解析答案discuss页的url
        # 对于每一个找到的url，拼接成完整的url
        for item in res:
            item = item['href']
            item = item[1:]     # 将点截掉
            solutionurls.append('http://acm.hdu.edu.cn/discuss/problem%s' % item)  # 拼接url

        for url in solutionurls:
            r = self.session.get(url)       # get每个完整的url
            soup = BeautifulSoup(r.text, 'html.parser')
            disshow = soup.find('pre', id='disshow').text   # 找到代码所在的tag，获取text

            diss = re.search(re.compile(r'#include.+', re.S), disshow)     # re.S 开启多行模式匹配###中间可能有空格什么的
            if diss:
                solutions.append(diss.group())      # 将代码存到要返回的list中
        return solutions

    def getbaidu(self, problemID):
        """
        从百度搜索题号，获取csdn博客中的题解
        :param problemID: 题号
        :return: 一个list，可能包含数个题解
        """
        solutions = []
        solutionurls = []
        url = r'http://www.baidu.com/s?wd=hdu%20' + str(problemID)      # 用题号拼接url

        baidusession = requests.Session()       # 新建一个用于百度搜索的session
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36'}
        baidusession.headers.update(headers)
        r = baidusession.get(url)

        soup = BeautifulSoup(r.text, 'html.parser')
        res = soup.find_all('a', attrs={'target': '_blank', 'class': 'c-showurl',
                                  'style': 'text-decoration:none;'})
        for item in res:
            if re.match('blog.csdn.net', item.text):
                solutionurls.append(item['href'])

        for item in solutionurls:
            r = baidusession.get(item)

            soup = BeautifulSoup(r.text, 'html.parser')
            code = soup.find(attrs={'name': '_code', 'class': 'cpp'})
            if code:
                # 先验证博客标题，如果标题包含题号，则继续
                title = soup.find('span', class_='link_title')
                pos = (title.text).find(str(problemID))
                if pos == -1:     # 若果不包含题号，break
                    break
                solutions.append(code.text)

        print(problemID, 'solutions finded: ', len(solutions))
        return solutions

    def getacweb(self, problemID):

        url = 'http://accepted.com.cn/hdoj%s/' % str(problemID)
        acsession = requests.Session()
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36'}
        acsession.headers.update(headers)
        r = acsession.get(url)
        #f = open('temp.html', 'wb')
        #f.write(r.text.encode('utf-8'))
        #f.close()
        soup = BeautifulSoup(r.text, 'html.parser')
        res = soup.find('textarea', attrs={'wrap': 'soft', 'class': 'crayon-plain print-no', 'data-settings': 'dblclick'})
        #print(res.text)
        if res:
            return res.text
        else:
            return None

    def autorun(self, start=1000, end=5639, interval=5):
        """
        开始运行AC自动机
        :param start: 开始题号
        :param end: 结束题号
        :param interval: 每次提交设置间隔时间
        """
        language = 0
        for problemID in range(start, end):
            # 先判断是否已经ac
            if str(problemID) not in c.getsolved(user):
                print(problemID, 'is not AC, start solving it...')
                # 解决这道没有AC的题目
                answers = c.getbaidu(problemID)
                if answers:
                    for answer in answers:
                        if str(problemID) not in c.getsolved(user):
                            # 判断语言
                            if answer.find('iostream') != -1:
                                language=2
                            elif answer.find('cstdio') != -1:
                                language=2
                            elif answer.find('stdio.h') != -1:
                                language=0
                            else:
                                print('language=???')
                                continue
                            print('language=', language)
                            c.submit(problemID, answer, language=language)
                            time.sleep(interval)
                        else:
                            break

    def autorunac(self, start=1000, end=5639, interval=5):
        language = 0
        for problemID in range(start, end):
            # 先判断是否已经ac
            if str(problemID) not in c.getsolved(user):
                print(problemID, 'is not AC, start solving it...')
                # 解决这道没有AC的题目
                time.sleep(3)
                answer = c.getacweb(problemID)
                if answer:
                    if str(problemID) not in c.getsolved(user):
                        # 判断语言
                        if answer.find('stdio.h') != -1:
                            language=2
                        elif answer.find('cstdio') != -1:
                            language=2
                        elif answer.find('iostream') != -1:
                            language=0
                        else:
                            print('language=???')
                            continue
                        print('language=', language)
                        c.submit(problemID, answer, language=language)
                        time.sleep(interval)
                    else:
                        break

if __name__ == '__main__':
    c = ACM_Module()
    user = 'cbdbs'
    c.login(user, 'daydayup')
    c.getstatus('cbdbs')
    #c.autorun(start=1002)
    #c.getacweb(1000)
    #c.autorunac(start=3532)