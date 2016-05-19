#!/usr/bin/env python
# -*- coding:utf-8 -*-

import requests
import configparser

class Login(object):
    def __init__(self):
        cf = configparser.ConfigParser()
        cf.read('config.ini')
        self.UA = cf.get('http', 'UA')
        self.username = cf.get('user', 'username')
        self.password = cf.get('user', 'password')

        self.session = requests.Session()
        self.session.headers.update({'User-Agent': self.UA})

    def login(self):
        url = 'http://acm.hdu.edu.cn/userloginex.php?action=login'
        data = {
            'username': self.username,
            'passwrod': self.password,
            'login': 'Sign In'
        }
        headers = {
            'host': 'acm.hdu.edu.cn',
            'origin': 'http://acm.hdu.edu.cn',
            'referer': 'http://acm.hdu.edu.cn/'
        }
        r = self.session.post(url, data=data, headers=headers)
        print('Login Status Code: ' + str(r.status_code == requests.codes.ok) )
