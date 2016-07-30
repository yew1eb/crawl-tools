#!/usr/bin/env python
# -*- coding:utf-8 -*-
import hashlib
from multiprocessing import Pool
import urllib.request

results = set()

def do_it(x):
    prefix = "20160522yew1eb" + str(x)
    i = 0
    while True:
        i += 1
        b = hashlib.md5()
        checkcode = prefix + str(i)
        b.update(  checkcode.encode() )
        if b.hexdigest()[0:6] == "000000":
            print(x, i, checkcode, b.hexdigest())
            return i

def post(checkcode):

    req = urllib.request.Request(
            "http://www.qlcoder.com/train/handsomerank?_token=Im1ZIvDF0XXx6sXtXZiiVPAiGL7A9wbWhxbSUhnH&user=yew1eb&checkcode=" + str(
                checkcode))
    urllib.request.urlopen(req)

if __name__ == '__main__':
    N = 1005
    pool = Pool(8)
    results = pool.map(do_it, range(1002,N+1))

    for i in range(0,N):
        post(results[i])
