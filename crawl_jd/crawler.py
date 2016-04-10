#!/usr/bin/env python
# -*- coding:utf-8 -*-

import re
import urllib.request
from bs4 import BeautifulSoup

class crawler:

    # 北邮人和水木清华的BBS结构一样，配置基本的HTML元素信息、感兴趣的信息以及需要过滤掉的信息配置
    def __init__(self, title_keyword, limit_keyword, sources):
        self.req_conf = {
			'BYR' : {
				'host' : 'http://bbs.byr.cn',
				'url'  : 'http://bbs.byr.cn/board/JobInfo',
				'url_attr' : {
					'href'   : re.compile('^/article/JobInfo/\d+$'),
					'title'  : None,
					'target' : None
				}
			},
			'NS_XZ' :{
				'host' : 'http://www.newsmth.net/',
				'url'  : 'http://www.newsmth.net/nForum/board/Career_Campus',
				'url_attr' : {
					'href'   : re.compile('^/nForum/article/Career_Campus/\d+$'),
					'title'  : None,
					'target' : None
				}
			},
			'NS_SZ' :{
				'host' : 'http://www.newsmth.net/',
				'url'  : 'http://www.newsmth.net/nForum/board/Career_Upgrade',
				'url_attr' : {
					'href'   : re.compile('^/nForum/article/Career_Upgrade/\d+$'),
					'title'  : None,
					'target' : None
				}
			},
			'NS_LT' :{
				'host' : 'http://www.newsmth.net/',
				'url'  : 'http://www.newsmth.net/nForum/board/ExecutiveSearch',
				'url_attr' : {
					'href'   : re.compile('^/nForum/article/ExecutiveSearch/\d+$'),
					'title'  : None,
					'target' : None
				}
			},
			'headers' : {
				"Accept":"text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
				"Accept-Language": "zh-cn",
				"X-Requested-With" : "XMLHttpRequest"
			}
		}
        self.tgt_time_attr = {
            'class' : re.compile('^title_10\w*$')
        }
        self.title_keyword = title_keyword
        self.limit_keyword = limit_keyword
        self.job_sources = sources
        self.first_flag = True

        # 获取目标HTML中的招聘信息
        def get_articles_from_html(self, host, tgt_html, source):
            print(tgt_html)
            req = urllib.request.Request(tgt_html, headers=self.req_conf['headers'])
            rep = urllib.request.urlopen(req)
            art_tags = BeautifulSoup(rep.read().decode('GBK')).find_all()