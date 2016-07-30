#!/usr/bin/env python
# -*- coding:utf-8 -*-
import requests

url = 'http://www.qlcoder.com/train/gayregister'
data = {}
session = requests.session()
headers = {
    'Content-Type':'application/x-www-form-urlencoded',
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.102 Safari/537.36',
}
rg = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q','r','s','t','u','v','w','x','y','z']
for a in rg:
    for b in rg:
        for c in rg:
            username = 'zfx'+a+b+c
            password = 'xyz'+a+b+c+'abc'+a+b+c+'xyz'+a+b+c+'abc'+a+b+c
            data['eyJpdiI6ImNOVFBIY3JWckkzdERGTDE3Mjh1MXc9PSIsInZhbHVlIjoiZnl1a29uRElyNmhIK2NTZTREcGxockROQ1N5QlNiS0NGeExPbnFSUDFjST0iLCJtYWMiOiJiMmNiOTFhNDJmZmNkZmFjOTQ3NjAwMGNhMWJlM2Q1YzBlMTUwZmVhNmZmZTE2MjEyZTYwOWNlY2FkMDU1NzljIn0=']= password
            data['eyJpdiI6IlN5M1gyZ1dmZE40cWorR1orRmRnc0E9PSIsInZhbHVlIjoiWGRBSTA3TldzeVVRZGI2SmZqK25XTGtTS0FkbXdFTFp5VHBRY29ienlyWT0iLCJtYWMiOiJlN2E3ZjQ3NTdiNTcwODU2ZTU3MzlmMzQzY2RhM2MxOTY2MGQ4NmM4ZjA2MGJiZDU2MTJmMDk0MzU2NzE3ZDI4In0=']='1'
            data['eyJpdiI6IlJSUVpMdXZRd2Y2QkRGTWJBR3FXaXc9PSIsInZhbHVlIjoiWTB2cG9Qc1RXaGh0VlZocFJKZDZ2ZW5qUm1YK2laQ241dXQyU1RXcit6RT0iLCJtYWMiOiI0ZWNiNmUyYWViMDBhNDI2NWYzMWQxMThkZTYyODhiZWVlOTY3NjcwNmI1OTY1YjlmNjAzYmU3YzlmNzRkYTdkIn0=']=username
            data['eyJpdiI6IkFUak9HdGpoOWtQT3Q5V1oydlpWVXc9PSIsInZhbHVlIjoiRU9PZzk3bDdTMUxGM0g4QnFnY2JUUEQxM1wvM0lpczJpTzRjYzFja2RzbWM9IiwibWFjIjoiZjdiYzkzNDg1MDI2ODA4ZDA0NjVkYzlhMDBjOGM0ZmNkODVmYjRkMDA0YzExZTY1OTBkYTc5M2Q0MDgwMzA3YiJ9']='zzz@163.com'
            data['eyJpdiI6InBRVnF6RHBkc3ViZFFGN3VxZFJ3eVE9PSIsInZhbHVlIjoiNytpVFIydndlNTY4ajNtemZFa2ZcL25STEIyZlh4bmhFemN5bDh5b29tb0E9IiwibWFjIjoiNmQyOGQxZjQ1MzY2NmJiZDBkNjg5ODY0OTQyOTk2NzRmMjEzYWUwYzE3MGRmN2ViNDAzYTgwNDc3NDgxN2YxYSJ9']='yew1eb'
            data['eyJpdiI6IkQ4Sm5cL0JwdkhsQXlaY25mQ0RcL3Y3Zz09IiwidmFsdWUiOiJUMzdUbFp6cGxEendpUUtBZm9UMnltSTdlVkd2bEdva1wvOXRHVWQ3R0t6Zz0iLCJtYWMiOiI4NWVmNThiNGM2NWU3YmVhNjRhMjQxMTg5ZWNjYTlhNjZiYTM2ZmQzMTgxZDBjYmFhMzcyMTQ2NjU5YTQwYmFiIn0=']='19850105'
            data['eyJpdiI6ImtlclRwbEdmQ0Y4UFBUNDRHOUZUWGc9PSIsInZhbHVlIjoiVGNxR2FCQm9lZmhoUWUyRkVOTzFYaXUxSm1JUXREYlFpb25hNE9JRmloWT0iLCJtYWMiOiJkYmRlMDhlMjU0Zjk5ZGMzMWM1MzBmZDcxMTc0OWQ5ZDJmN2IwNDczYTBlMTJhNDA5Y2IyODY2N2JiMWExZTRkIn0=']=password
            data['eyJpdiI6IjFDZkhWSEVDME5SeVViTXFxaGhvXC9BPT0iLCJ2YWx1ZSI6InJrdXo3eFAxZEdQTzRtK3F5b1NOeFBleE9kbVJ0S0lIWDgxcG1lUlFqalk9IiwibWFjIjoiMTI0NmQ0ZDA1MGFlYzkwYzRkMzczYzA4MTUxOTA2ZTYxY2QxNzk1NDc4NWM1MGM5MGM2MGY5YWYzOTQ0N2JmMCJ9']='12345678911'
            data['_token'] = 'Im1ZIvDF0XXx6sXtXZiiVPAiGL7A9wbWhxbSUhnH'
            r = session.post(url, data, headers)
            print(r.text)