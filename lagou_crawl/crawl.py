#! -*-coding:utf-8 -*-
'''
Function:计算拉勾网编程语言的关键词排名
Author:蘭兹
'''
import csv
import datetime
import json
import re
import time
from collections import OrderedDict
from urllib import request, parse

from bs4 import BeautifulSoup as Bs

from lagou_crawl.pullword import pullword
import jieba

starttime = datetime.datetime.now()

url = r'http://www.lagou.com/jobs/positionAjax.json?city=%E5%8C%97%E4%BA%AC'

keyword = 'java'  # input('请输入您所需要查找的关键词 : ')


def get_blacklist():
    file = open('blacklist.txt', mode='r+', encoding='utf-8')
    blacklist = []
    for line in file:
        words = line.strip().split(' ')
        for word in words:
            if len(word) > 1:
                blacklist.append(word)
    return blacklist


blacklist = get_blacklist()


# 获取职位的查询页面(参数分别为网址，当前页面数，关键词)
def get_page(url, pn, keyword):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
                      'Chrome/45.0.2454.85 Safari/537.36 115Browser/6.0.3',
        'Host': 'www.lagou.com',
        'Connection': 'keep-alive',
        'Origin': 'http://www.lagou.com'
    }
    if pn == 1:
        boo = 'true'
    else:
        boo = 'false'
    # 通过页面分析，发现浏览器提交的FormData包括以下参数
    data = parse.urlencode([
        ('first', boo),
        ('pn', pn),
        ('kd', keyword)
    ])
    req = request.Request(url, headers=headers)
    page = request.urlopen(req, data=data.encode('utf-8')).read()
    page = page.decode('utf-8')
    return page


# 获取所需的岗位id,每一个招聘页面详情都有一个所属的id索引
def read_id(page):
    tag = 'positionId'
    page_json = json.loads(page)
    page_json = page_json['content']['positionResult']['result']
    company_list = []
    for i in range(15):
        company_list.append(page_json[i].get(tag))
    return company_list


# 获取当前招聘关键词的最大页数，大于30的将会被覆盖，所以最多只能抓取30页的招聘信息
def read_max_page(page):
    page_json = json.loads(page)
    max_page_num = 30
    if max_page_num > 30:
        max_page_num = 30
    return max_page_num


# 获取职位页面，由ositionId和BaseUrl组合成目标地址
def get_content(company_id):
    fin_url = r'http://www.lagou.com/jobs/%s.html' % company_id
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
                      'Chrome/45.0.2454.85 Safari/537.36 115Browser/6.0.3',
        'Host': 'www.lagou.com',
        'Connection': 'keep-alive',
        'Origin': 'http://www.lagou.com'
    }
    req = request.Request(fin_url, headers=headers)
    page = request.urlopen(req).read()
    content = page.decode('utf-8')
    return content


# 获取职位需求（通过re来去除html标记），可以将职位详情单独存储
def get_result(content):
    soup = Bs(content, 'lxml')
    job_description = soup.select('dd[class="job_bt"]')
    job_description = str(job_description[0])
    rule = re.compile(r'<[^>]+>')
    result = rule.sub('', job_description)
    return result


# 过滤关键词：目前筛选的方式只是选取英文关键词
def search_skill_by_pullword(source):
    words_list = pullword(source, threshold=0, debug=1)
    return words_list


def search_skill_by_jieba(source):
    words = jieba.cut(source, cut_all=False)
    words_list = []
    for word in words:
        words_list.append([word, 1])
    return words_list


# 对结果进行存储并生成Area图
def save_csv(count_dict, file_name):
    csvfile = open(r'%s.csv' % file_name, 'w+', encoding='utf-8')
    writer = csv.writer(csvfile)
    writer.writerow(['关键词', '词频'])
    for item in count_dict.items():
        writer.writerow(item)
    csvfile.close()


######################################################################################

if __name__ == '__main__':
    max_pn = read_max_page(get_page(url, 1, keyword))  # 获取招聘页数
    count_dict = {}  # 关键词总表
    for pn in range(1, max_pn):
        print('***********************正在抓取第%s页信息***********************' % pn)
        page = get_page(url, pn, keyword)
        company_list = read_id(page)
        for company_id in company_list:
            content = get_content(company_id)
            job_desc = get_result(content)  # 职位描述
            skill_keys = search_skill_by_jieba(job_desc)  # 抽取长尾词 [[词,词频], ...]
            for item in skill_keys:
                key = item[0].strip().lower()
                if len(key) < 2:
                    continue
                cnt = 1
                if len(item) > 1:
                    cnt = float(item[1])
                else:
                    print(key)

                if key in count_dict:
                    count_dict[key] += cnt
                else:
                    count_dict[key] = cnt

    result_dict = OrderedDict(sorted(count_dict.items(), key=lambda e: e[1], reverse=True))
    print('***********************开始统计关键词出现频率***********************')
    print(result_dict)
    save_csv(result_dict, keyword)
    print('***********************正在保存到桌面***********************')
    endtime = datetime.datetime.now()
    time = (endtime - starttime).seconds
    print('总共用时：%s s' % time)
